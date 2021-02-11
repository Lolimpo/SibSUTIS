from random import randint

import pandas as pd
import graphviz
from sklearn import tree
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split


if __name__ == '__main__':
    nan_value = float("NaN")
    data = pd.read_csv('ac_heart_data.csv', header=None)
    data.replace("?", nan_value, inplace=True)
    data.dropna(inplace=True)
    x_data = data.loc[1:, 0:12]
    y_data = data.loc[1:, 13]

    for i in range(10):
        X_train, X_test, Y_train, Y_test = train_test_split(x_data, y_data, test_size=0.3, random_state=randint(0, 10000))
        clf = tree.DecisionTreeClassifier(random_state=0, max_depth=6, max_leaf_nodes=12)
        clf.fit(X_train, Y_train)
        prediction = clf.predict(X_test)
        print(f"Accuracy: {accuracy_score(Y_test, prediction) * 100:.3}%")

        # dot_data = tree.export_graphviz(clf, out_file=None,
        #                                 class_names=['Healthy', 'Cancer'],
        #                                 filled=True)
        # graph = graphviz.Source(dot_data)
        # graph.render('test-output/round-table.gv', view=True)
