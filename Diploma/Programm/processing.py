from datetime import datetime
import time

import numpy as np
import pandas as pd
import cv2
import pickle

from tensorflow.keras.models import load_model

# Считываем все названия классов
labels = pd.read_csv('data/label_names_eng.csv')

# Загружаем готовую модель-детектор знаков с конфигурационным файлом
network = cv2.dnn.readNetFromDarknet('data/yolov3_ts_test.cfg', 'data/znaki_rtx_final.weights')
# Включаем дополнительные настройки графического ускорителя для увеличения скорости рабоыт программы
network.setPreferableBackend(cv2.dnn.DNN_BACKEND_CUDA)
network.setPreferableTarget(cv2.dnn.DNN_TARGET_CUDA_FP16)
layers_names_all = network.getLayerNames()
# print(layers_names_all)

# Загружаем модель-классификатор
model = load_model('models/model-new.h5')
with open('data/mean_image_rgb.pickle', 'rb') as f:
    mean = pickle.load(f, encoding='latin1')
# print(mean['mean_image_rgb'].shape)

layers_names_output = [layers_names_all[i[0] - 1] for i in network.getUnconnectedOutLayers()]
# print(layers_names_output)

# Минимальная вероятность чтобы избавиться от слабых обнаружений
probability_minimum = 0.5
# Устанавливаем минимальный порог для фильтрации слабых граничных рамок методом подавления немаксимумов
threshold = 0.3
# Генерируем массив цветов рамок для каждого из классов
colours = np.random.randint(0, 255, size=(len(labels), 3), dtype='uint8')


def process_image(path):
    """ Метод в котором обрабатывается изображение """
    # Считываем изображение
    image_BGR = cv2.imread(path)
    # Получаем высоту и ширину изображения
    h, w = image_BGR.shape[:2]

    # Получаем объект с необработанными данными из изображения
    blob = cv2.dnn.blobFromImage(image_BGR, 1 / 255.0, (416, 416), swapRB=True, crop=False)
    # print(blob.shape)

    # Проходимся по изображению через слои нашей модели и подсчитываем время обработки
    network.setInput(blob)
    start = time.time()
    output_from_network = network.forward(layers_names_output)
    end = time.time()
    print(f'Objects Detection took {end - start:.5f} seconds')

    # Определяем границы найденых знаков и отсекаем их в отдельный массив,
    # чтобы в дальнейшем использовать на модели-классификаторе
    bounding_boxes = []
    confidences = []
    class_numbers = []
    for result in output_from_network:
        for detected_objects in result:
            scores = detected_objects[5:]
            class_current = np.argmax(scores)
            confidence_current = scores[class_current]

            if confidence_current > probability_minimum:
                box_current = detected_objects[0:4] * np.array([w, h, w, h])

                x_center, y_center, box_width, box_height = box_current
                x_min = int(x_center - (box_width / 2))
                y_min = int(y_center - (box_height / 2))

                bounding_boxes.append([x_min, y_min, int(box_width), int(box_height)])
                confidences.append(float(confidence_current))
                class_numbers.append(class_current)

    # Применяем алгоритм подавления немаксимумов для отсечения ошибочно найденных объектов
    # и уточнения границ рамок
    results = cv2.dnn.NMSBoxes(bounding_boxes, confidences, probability_minimum, threshold)

    # Смотрим осталось ли что-то после подавления
    if len(results) > 0:
        # Проходимся по все результатам
        for i in results.flatten():
            x_min, y_min = bounding_boxes[i][0], bounding_boxes[i][1]
            box_width, box_height = bounding_boxes[i][2], bounding_boxes[i][3]
            # Получаем фрагмент изображения на основе предсказания предыдущей модели
            c_ts = image_BGR[y_min: y_min + int(box_height), x_min: x_min + int(box_width), :]

            if c_ts.shape[:1] == (0,) or c_ts.shape[1:2] == (0,):
                pass
            # Если все хорошо - получаем blob этого фрагмента
            else:
                blob_ts = cv2.dnn.blobFromImage(c_ts, 1 / 255.0, size=(32, 32), swapRB=True, crop=False)
                blob_ts[0] = blob_ts[0, :, :, :] - mean['mean_image_rgb']
                blob_ts = blob_ts.transpose(0, 2, 3, 1)
                # Получаем все предсказания классов
                scores = model.predict(blob_ts)
                # Выбираем максимальное из них
                prediction = np.argmax(scores)
                print(labels['SignName'][prediction])

                colour_box_current = colours[class_numbers[i]].tolist()

                cv2.rectangle(image_BGR, (x_min, y_min), (x_min + box_width, y_min + box_height),
                              colour_box_current, 2)
                text_box_current = '{}: {:.4f}'.format(labels['SignName'][prediction], confidences[i])
                # text_box_current = '{}: {:.4f}'.format('Кирилический-Тест 123', confidences[i])
                cv2.putText(image_BGR, text_box_current, (x_min - 10, y_min - 5),
                            cv2.FONT_HERSHEY_COMPLEX, 0.5, colour_box_current, 2)

    cv2.imwrite('result.png', image_BGR)
    return True, end - start


def process_camera():
    cap = cv2.VideoCapture(1)
    # cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
    # cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
    h, w = None, None
    t, f = 0, 0
    while True:
        ret, frame = cap.read()
        if not ret:
            break

        if w is None or h is None:
            h, w = frame.shape[:2]

        blob = cv2.dnn.blobFromImage(frame, 1 / 255.0, (416, 416), swapRB=True, crop=False)

        network.setInput(blob)
        start = time.time()
        output_from_network = network.forward(layers_names_output)
        end = time.time()

        f += 1
        t += end - start
        print('Frame number {0} took {1:.5f} seconds'.format(f, end - start))

        bounding_boxes = []
        confidences = []
        class_numbers = []

        for result in output_from_network:
            for detected_objects in result:
                scores = detected_objects[5:]
                class_current = np.argmax(scores)
                confidence_current = scores[class_current]
                if confidence_current > probability_minimum:
                    box_current = detected_objects[0:4] * np.array([w, h, w, h])

                    x_center, y_center, box_width, box_height = box_current
                    x_min = int(x_center - (box_width / 2))
                    y_min = int(y_center - (box_height / 2))

                    bounding_boxes.append([x_min, y_min, int(box_width), int(box_height)])
                    confidences.append(float(confidence_current))
                    class_numbers.append(class_current)

        results = cv2.dnn.NMSBoxes(bounding_boxes, confidences, probability_minimum, threshold)

        if len(results) > 0:
            for i in results.flatten():
                x_min, y_min = bounding_boxes[i][0], bounding_boxes[i][1]
                box_width, box_height = bounding_boxes[i][2], bounding_boxes[i][3]

                c_ts = frame[y_min:y_min+int(box_height), x_min:x_min+int(box_width), :]

                if c_ts.shape[:1] == (0,) or c_ts.shape[1:2] == (0,):
                    pass
                else:
                    blob_ts = cv2.dnn.blobFromImage(c_ts, 1 / 255.0, size=(32, 32), swapRB=True, crop=False)
                    blob_ts[0] = blob_ts[0, :, :, :] - mean['mean_image_rgb']
                    blob_ts = blob_ts.transpose(0, 2, 3, 1)

                    scores = model.predict(blob_ts)
                    prediction = np.argmax(scores)

                    colour_box_current = colours[class_numbers[i]].tolist()

                    cv2.rectangle(frame, (x_min, y_min), (x_min + box_width, y_min + box_height),
                                  colour_box_current, 2)

                    text_box_current = '{}: {:.4f}'.format(labels['SignName'][prediction], confidences[i])
                    cv2.putText(frame, text_box_current, (x_min - 10, y_min - 5),
                                cv2.FONT_HERSHEY_SIMPLEX, 0.5, colour_box_current, 2)

        cv2.namedWindow('Image from camera', cv2.WINDOW_AUTOSIZE)
        cv2.imshow('Camera view', frame)

        if cv2.waitKey(1) & 0xFF == ord('q') or ord('й'):
            break

    cap.release()
    cv2.destroyAllWindows()
    return f, t


def process_video(path):
    video = cv2.VideoCapture(path)
    writer = None
    h, w = None, None
    frames, t = 0, 0
    while True:
        ret, frame = video.read()

        if not ret:
            break

        if w is None or h is None:
            h, w = frame.shape[:2]

        blob = cv2.dnn.blobFromImage(frame, 1 / 255.0, (416, 416), swapRB=True, crop=False)

        network.setInput(blob)
        start = time.time()
        output_from_network = network.forward(layers_names_output)
        end = time.time()

        frames += 1
        t += end - start
        print('Frame number {0} took {1:.5f} seconds'.format(f, end - start))

        bounding_boxes = []
        confidences = []
        class_numbers = []

        for result in output_from_network:
            for detected_objects in result:
                scores = detected_objects[5:]
                class_current = np.argmax(scores)
                confidence_current = scores[class_current]
                if confidence_current > probability_minimum:
                    box_current = detected_objects[0:4] * np.array([w, h, w, h])

                    x_center, y_center, box_width, box_height = box_current
                    x_min = int(x_center - (box_width / 2))
                    y_min = int(y_center - (box_height / 2))

                    bounding_boxes.append([x_min, y_min, int(box_width), int(box_height)])
                    confidences.append(float(confidence_current))
                    class_numbers.append(class_current)

        results = cv2.dnn.NMSBoxes(bounding_boxes, confidences, probability_minimum, threshold)

        if len(results) > 0:
            for i in results.flatten():
                x_min, y_min = bounding_boxes[i][0], bounding_boxes[i][1]
                box_width, box_height = bounding_boxes[i][2], bounding_boxes[i][3]

                c_ts = frame[y_min:y_min+int(box_height), x_min:x_min+int(box_width), :]

                if c_ts.shape[:1] == (0,) or c_ts.shape[1:2] == (0,):
                    pass
                else:
                    blob_ts = cv2.dnn.blobFromImage(c_ts, 1 / 255.0, size=(32, 32), swapRB=True, crop=False)
                    blob_ts[0] = blob_ts[0, :, :, :] - mean['mean_image_rgb']
                    blob_ts = blob_ts.transpose(0, 2, 3, 1)

                    scores = model.predict(blob_ts)
                    prediction = np.argmax(scores)

                    colour_box_current = colours[class_numbers[i]].tolist()

                    cv2.rectangle(frame, (x_min, y_min), (x_min + box_width, y_min + box_height),
                                  colour_box_current, 2)

                    text_box_current = '{}: {:.4f}'.format(labels['SignName'][prediction], confidences[i])
                    cv2.putText(frame, text_box_current, (x_min - 10, y_min - 5),
                                cv2.FONT_HERSHEY_SIMPLEX, 0.5, colour_box_current, 2)

        if writer is None:
            fourcc = cv2.VideoWriter_fourcc(*'mp4v')
            writer = cv2.VideoWriter('result.mp4', fourcc, 25,
                                     (frame.shape[1], frame.shape[0]), True)
        writer.write(frame)

    video.release()
    writer.release()
    return True, frames, t
