import numpy as np

class Calculus:
    def __init__(self):
        pass


    def extended_matrix(self, X):
        n = len(X)
        Xe = np.c_[np.ones((n, 1)), X]
        
        return Xe
    
    def extended_quadratic_matrix(self, X1, X2):
        X1 = X1.reshape(-1, 1)
        X2 = X2.reshape(-1, 1)
        X1_squared = X1 ** 2
        X2_squared = X2 ** 2
        X1_X2 = X1 * X2
        Xq = np.concatenate([X1, X2, X1_squared, X1_X2, X2_squared], axis=1)
        Xq_e = np.c_[np.ones((len(Xq), 1)), Xq]
        return Xq_e
    
    
    def normal_equation(self, Xe, y):
        beta = np.linalg.inv(Xe.T.dot(Xe)).dot(Xe.T).dot(y)

        return beta
    

    def feature_normalization(self, X):
        mu = np.mean(X, axis=0)
        sigma = np.std(X, axis=0)
        X_norm = (X - mu) / sigma

        return mu, sigma, X_norm
    

    def cost_function(self, Xe, y, beta):
        n = len(y)
        j = np.dot(Xe, beta) - y
        J = (j.T.dot(j)) / n

        return J    
    
    
    def gradient_descent(self, X, y, alpha, N):
        beta = np.zeros(X.shape[1])
        n = len(y)
        cost_history = []            

        for _ in range(N):
            beta = beta - alpha / n * X.T.dot(X.dot(beta) - y)

            cost = self.cost_function(X, y, beta)
            cost_history.append(cost)

        return beta, cost_history

    
    def sigmoid(self, z):
        return 1 / (1 + np.exp(-z))
    
    
    def logistic_cost_function(self, Xe, y, beta):
        n = len(y)
        j = self.sigmoid(Xe.dot(beta))
        J = -np.mean(y * np.log(j) + (1 - y) * np.log(1 - j))

        return J
    
    
    def logistic_gradient_descent(self, X, y, alpha, N):
        beta = np.zeros(X.shape[1])
        n = len(y)
        cost_history = []

        for _ in range(N):
            beta = beta - alpha / n * X.T.dot(self.sigmoid(X.dot(beta)) - y)

            cost = self.logistic_cost_function(X, y, beta)
            cost_history.append(cost)

        return beta, cost_history
    

    def mean_square_error(self, y_train, y_test):
        return np.mean((y_train - y_test) ** 2)