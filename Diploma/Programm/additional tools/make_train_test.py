import os


path_to_images = r'C:\Users\Lolimpo\Google Drive\SibSUTIS\Labs\4 course\Diploma\Program\data\yolo_formated'

os.chdir(path_to_images)
p = []
for cur_dir, dirs, files in os.walk('..'):
    for f in files:
        if f.endswith('.jpg'):
            path_to_save = path_to_images + '\\' + f
            p.append(path_to_save + '\n')

p_test = p[:int(len(p) * 0.15)]
p = p[int(len(p) * 0.15):]

with open('train.txt', 'w') as t_file:
    for e in p:
        t_file.write(e)

with open('test.txt', 'w') as t_file:
    for e in p_test:
        t_file.write(e)

c = 0
with open(path_to_images + '\\' + 'classes.names', 'w') as names, open(path_to_images + '\\' + 'classes.txt', 'r') as txt:
    for line in txt:
        names.write(line)
        c += 1

with open(path_to_images + '\\' + 'ts_data.data', 'w') as data:
    data.write('classes = ' + str(c) + '\n')
    data.write('train = ' + path_to_images + '/' + 'train.txt' + '\n')
    data.write('valid = ' + path_to_images + '/' + 'test.txt' + '\n')
    data.write('names = ' + path_to_images + '/' + 'classes.names' + '\n')
    data.write('backup = backup')
