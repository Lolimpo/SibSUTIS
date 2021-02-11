import math
import operator
import numpy as np
from scipy.spatial import distance
from sklearn.model_selection import train_test_split


class KNN:

    def max_heapify(self, A, i):
        left = 2 * i + 1
        right = 2 * i + 2
        largestNode = i

        if left < len(A) and A[left][0] > A[largestNode][0]:
            largestNode = left
        if right < len(A) and A[right][0] > A[largestNode][0]:
            largestNode = right

        if largestNode != i:
            A[i], A[largestNode] = A[largestNode], A[i]
            self.max_heapify(A, largestNode)

    def make_MaxHeap(self, A):
        for i in range(len(A) // 2, -1, -1):
            self.max_heapify(A, i)

    def fit(self, X_train, Y_train):
        self.X_train = X_train
        self.Y_train = Y_train

    def closestPt(self, X_feature_set, n):
        filled = False
        closest_Points = []

        for i in range(len(self.X_train)):
            Euc_distance = distance.euclidean(X_feature_set, self.X_train[i])

            if len(closest_Points) < n:
                closest_Points.append((Euc_distance, self.Y_train[i]))

            if len(closest_Points) == n and filled == False:
                self.make_MaxHeap(closest_Points)
                filled = True

            elif filled:
                if Euc_distance < closest_Points[0][0]:
                    closest_Points[0] = (Euc_distance, self.Y_train[i])
                    self.max_heapify(closest_Points, 0)

        if len(closest_Points) == 1:
            return closest_Points[0][1]

        WeightedDistance = None
        predictedLabel = None
        label_dict = {}

        for item in closest_Points:
            if item[1] not in label_dict.keys():
                if (item[0]) != 0.0:
                    label_dict[item[1]] = 1 / (item[0])
                elif (item[0]) == 0.0:
                    predictedLabel = item[1]

                    return predictedLabel
            elif item[1] in label_dict.keys():
                if (item[0]) != 0.0:
                    label_dict[item[1]] += 1 / (item[0])
                elif (item[0]) == 0.0:
                    predictedLabel = item[1]

                    return predictedLabel

        for item in label_dict.keys():
            if WeightedDistance == None:
                WeightedDistance = label_dict[item]
                predictedLabel = item

            if label_dict[item] > WeightedDistance:
                WeightedDistance = label_dict[item]
                predictedLabel = item
        return predictedLabel

    def predict(self, X_feature_set, n=1):
        pred_label = self.closestPt(X_feature_set, n)
        return pred_label

    def validateAccuracy(self, X_test, Y_test, rounds=1, neighbors=1):
        for j in range(rounds):
            count = 0
            stored_accuracy = []
            for i in range(len(X_test)):
                label = self.predict(X_test[i], 1)
                if label == Y_test[i]:
                    count += 1
            stored_accuracy.append((count / len(X_test)) * 100)
        return sum(stored_accuracy) / float(len(stored_accuracy))

    def findOptimalK(self, X_test, Y_test):
        highest_acccuracy_value = None
        for i in range(1, 5):
            valAccuracy = self.validateAccuracy(X_test, Y_test, 1, i)
            if highest_acccuracy_value == None:
                highest_acccuracy_value = (i, valAccuracy)
            elif valAccuracy > highest_acccuracy_value[1]:
                highest_acccuracy_value = (i, valAccuracy)
        return highest_acccuracy_value[0]


def main():
    raw_data = np.genfromtxt('data2.csv', delimiter=',', skip_header=True)
    X_data = np.stack((raw_data[:, 0], raw_data[:, 1]), axis=1)
    Y_data = raw_data[:, 2]
    X_train, X_test, Y_train, Y_test = train_test_split(X_data, Y_data, stratify=Y_data, test_size=0.4, random_state=10)
    # for i in range(1, 6):
    #     score = LOO(X_train, Y_train, i)
    #     scores[i] = score
    #     print(f'{i}: {score:.4f}')
    # k = min(scores, key=scores.get)
    knnw = KNN()
    knnw.fit(X_train, Y_train)
    k = knnw.findOptimalK(X_test, Y_test)
    print(k)


if __name__ == '__main__':
    exit(main())
