import numpy as np
from sklearn.model_selection import train_test_split


class KWNN:
    def __init__(self, k, x, y):
        self.k = int(k)
        self.x = x
        self.y = y

    def predict(self, x):
        y = []
        if x.ndim > 1:
            for obs in x:
                y.append(self._predict(obs))
        else:
            y.append(self._predict(x))
        return y

    def _predict(self, obs):
        distance = np.sqrt(np.sum((self.x - obs) ** 2, axis=1))
        idx = np.argsort(distance)[:self.k]
        counts = np.bincount(self.y[idx].astype(int))

        if len(counts):
            prediction = np.argmax(counts)
        else:
            prediction = -1
        return prediction


def LOO(x, y, param=1):
    scores = []

    for i in range(len(x)):
        test_x, test_y = x[i], y[i]
        knn = KWNN(param, np.delete(x, i, axis=0), np.delete(y, i))
        scores.append(knn.predict(test_x)[0] != test_y)
    return sum(scores) / len(x)


def main():
    raw_data = np.genfromtxt('data2.csv', delimiter=',', skip_header=True)
    X_data = np.stack((raw_data[:, 0], raw_data[:, 1]), axis=1)
    Y_data = raw_data[:, 2]
    X_train, X_test, Y_train, Y_test = train_test_split(X_data, Y_data, stratify=Y_data,
                                                        test_size=0.33, random_state=12345)

    print("Searching the best k:")
    scores = {}
    for i in range(1, 6):
        score = LOO(X_train, Y_train, i)
        scores[i] = score
        print(f'{i}: {score:.4f}')
    k = min(scores, key=scores.get)
    print(f'Best chosen k = {k}')

    kwnn = KWNN(k, X_train, Y_train)
    predictions = kwnn.predict(X_test)
    mistakes = 0
    for i in range(len(Y_test)):
        print(f"Predicted: {predictions[i]}, Actual: {Y_test[i]}")
        if predictions[i] != Y_test[i]:
            mistakes += 1
    print(f"Mistakes were made: {mistakes} on selection size: {len(Y_test)}")
    print(f"Accuracy: {100 - (mistakes / len(Y_test) * 100):.3}%")


if __name__ == '__main__':
    exit(main())
