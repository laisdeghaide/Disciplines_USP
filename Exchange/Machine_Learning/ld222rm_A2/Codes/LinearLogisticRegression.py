import numpy as np
from Calculus import Calculus

class LinearLogisticRegreesion:
    def __init__(self):
        self.calculus = Calculus()
        self.mu = None
        self.sigma = None
        self.beta = None
        self.cost_history = []


    def fit(self, X, y, alpha=0.01, num_iterations=1000):
        self.mu, self.sigma, Xn = self.calculus.feature_normalization(X)
        Xn_e = self.calculus.extended_matrix(Xn)
        self.beta, self.cost_history = self.calculus.gradient_descent(Xn_e, y, alpha, num_iterations)

        return self.cost_history
    
    
    def predict(self, X):
        Xn = (X - self.mu) / self.sigma
        Xn_e = self.calculus.extended_matrix(Xn)
        z = Xn_e.dot(self.beta)
        y_pred = np.round(self.calculus.sigmoid(z))

        return y_pred
    

