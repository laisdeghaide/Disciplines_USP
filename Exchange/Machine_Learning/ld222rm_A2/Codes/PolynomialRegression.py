import numpy as np
from Calculus import Calculus

class PolynomialRegression:
    def __init__(self, degree=1):
        self.degree = degree
        self.calculus = Calculus()
        self.mu = None
        self.sigma = None
        self.beta = None


    def create_polynomial_features(self, X):
        X_polynomial = np.array(X)
        
        for d in range(2, self.degree+1):
            X_polynomial = np.concatenate((X_polynomial, X**d), axis=1)
        
        return X_polynomial
    

    def fit(self, X, y):
        #create polynomial features
        X_polynomial = self.create_polynomial_features(X)

        # normalize features
        self.mu, self.sigma, Xn = self.calculus.feature_normalization(X_polynomial)

        # extend matrix
        Xn_e = self.calculus.extended_matrix(Xn)

        # find optimal param
        self.beta = self.calculus.normal_equation(Xn_e, y)    


    def predict(self, X):
        #create polynomial features
        X_polynomial = self.create_polynomial_features(X)

        # normalize features
        Xn = (X_polynomial - self.mu) / self.sigma

        # extend matrix
        Xn_e = self.calculus.extended_matrix(Xn)

        # predict
        y_pred = Xn_e.dot(self.beta)

        return y_pred
        
        