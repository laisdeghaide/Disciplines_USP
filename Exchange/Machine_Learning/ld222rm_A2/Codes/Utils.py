import numpy as np
from matplotlib.colors import ListedColormap
from Calculus import Calculus

cmap_light = ListedColormap(['#FFAAAA', '#AAFFAA', '#AAAAFF'])
cmap_bold = ListedColormap(['#FF0000', '#00FF00', '#0000FF']) 

def get_sorted(x, y):
    xs, ys = zip(*sorted(zip(x, y)))
    return xs, ys


def data_split(data, test_size=0.3, random_state=None):
    sample_size = data.shape[0]
    
    if random_state:
        np.random.seed(random_state)

    np.random.shuffle(data)

    test_size = int(sample_size * test_size)

    train = data[test_size:]
    test = data[:test_size]

    X_train, y_train = train[:, :-1], train[:, -1]
    X_test, y_test = test[:, :-1], test[:, -1]

    return X_train, y_train, X_test, y_test

def mapFeatures(X1, X2, d):
    one = np.ones([len(X1), 1])
    Xe = np.c_[one, X1, X2]
    for i in range(2, d+1):
        for j in range(0, i+1):
            Xnew = X1**(i-j)*X2**j
            Xnew = Xnew.reshape(-1, 1)
            Xe = np.append(Xe, Xnew, 1)

    return Xe