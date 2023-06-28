import numpy as np

def compute_stress(X, Y, d_ij_star):
    n = X.shape[0]
    stress = 0.0
    total_pairs = 0

    for i in range(n):
        for j in range(i+1, n):
            dx = X[i] - X[j]
            dy = Y[i] - Y[j]
            norm_dx = np.linalg.norm(dx)
            norm_dy = np.linalg.norm(dy)

            if norm_dx == 0.0 or norm_dy == 0.0:
                continue

            stress += (norm_dx - norm_dy)**2 / (d_ij_star[i, j] + 1e-10)
            total_pairs += 1

    stress /= total_pairs

    return stress


def gradient_descent(X, Y, d_ij, d_ij_star, learning_rate):
    n = X.shape[0]
    delta_Y = np.zeros_like(Y)

    for i in range(n):
        for j in range(n):
            if i != j:
                denominator = d_ij_star[i, j] * (d_ij[i, j] + 1e-10)
                if denominator != 0:
                    factor = -2 / denominator  # Updated gradient factor
                    delta_Y[i] += factor * (Y[i] - Y[j])

    delta_Y *= learning_rate
    return delta_Y


def sammon(X, iter, epsilon, learning_rate):
    n = X.shape[0]

    # Precompute distances in the original space
    d_ij_star = np.zeros((n, n))
    for i in range(n):
        for j in range(i+1, n):
            dx = X[i] - X[j]
            d_ij_star[i, j] = np.linalg.norm(dx)
            d_ij_star[j, i] = d_ij_star[i, j]

    # Step 1: Start with a random two-dimensional layout Y
    Y = np.random.uniform(-1, 1, (n, 2))  # Initialize Y with random values between -1 and 1

    for it in range(iter):
        # Steps 2 and 3: Check stopping criteria (compute stress at intervals)
        if it % 5 == 0:
            stress = compute_stress(X, Y, d_ij_star)
            if stress < epsilon:
                break

        # Step 4: Update Y using gradient descent
        d_ij = np.zeros((n, n))
        for i in range(n):
            for j in range(i+1, n):
                dy = Y[i] - Y[j]
                d_ij[i, j] = np.linalg.norm(dy)
                d_ij[j, i] = d_ij[i, j]

        delta_Y = gradient_descent(X, Y, d_ij, d_ij_star, learning_rate)
        Y -= delta_Y  # Updated Y update direction

    return Y
