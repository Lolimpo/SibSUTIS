import pandas as pd
import os
import cv2
import numpy as np

os.cur
full_path_to_ts_dataset = 'C:\\Users\\Lolimpo\\Desktop\\dataset'

# Считываем всю информацию о дата-сете
ann1 = pd.read_csv(full_path_to_ts_dataset + '\\' + 'rtsd-d1-gt\\danger\\test_gt.csv')
ann2 = pd.read_csv(full_path_to_ts_dataset + '\\' + 'rtsd-d1-gt\\mandatory\\test_gt.csv')
ann3 = pd.read_csv(full_path_to_ts_dataset + '\\' + 'rtsd-d1-gt\\prohibitory\\test_gt.csv')
ann = pd.concat([ann1, ann2, ann3], join='inner')

classes = pd.read_csv(full_path_to_ts_dataset + '\\rtsd-r1\\numbers_to_classes.csv', header=0, index_col=0, squeeze=True).to_dict()
print(classes)


ann['center x'] = ''
ann['center y'] = ''
ann['class id'] = ''

ann['center x'] = (ann['x_from'] + (ann['x_from'] + ann['width'])) / 2
ann['center y'] = (ann['y_from'] + (ann['y_from'] + ann['height'])) / 2

values = []
for i in ann['sign_class']:
    for k, v in classes.items():
        if i == v:
            values.append(k)
            print(i, k)

ann['class id'] = values
print(ann.head(10))

r = ann.loc[:, ['filename',
                'class id',
                'center x',
                'center y',
                'width',
                'height']].copy()

print(r.head(5))
# Переходим в другую директорию
os.chdir(full_path_to_ts_dataset + '\\rtsd-d1-frames')

# Проходимся по всем файлам, подсчитываем значения для модели-YOLO, сохраняем аннотацию рядом с исходным изображением.
for cur_dir, dirs, files in os.walk('..'):
    for f in files:
        if f.endswith('.jpg'):
            image_name = f[:-4]

            image = cv2.imread(os.getcwd() + '\\test\\' + f)
            h, w = image.shape[:2]

            sub_r = r.loc[r['filename'] == f].copy()

            sub_r['center x'] = sub_r['center x'] / w
            sub_r['center y'] = sub_r['center y'] / h
            sub_r['width'] = sub_r['width'] / w
            sub_r['height'] = sub_r['height'] / h

            resulted_frame = sub_r.loc[:, ['class id',
                                           'center x',
                                           'center y',
                                           'width',
                                           'height']].copy()

            if resulted_frame.isnull().values.all():
                continue

            path_to_save = full_path_to_ts_dataset + '\\yolo_formated\\' + image_name + '.txt'
            resulted_frame.to_csv(path_to_save, header=False, index=False, sep=' ')
            path_to_save = full_path_to_ts_dataset + '\\yolo_formated\\' + image_name + '.jpg'
            cv2.imwrite(path_to_save, image)
