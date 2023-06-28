import numpy as np
from sklearn.cluster import KMeans

def bkmeans(X, k, iter):
    n = X.shape[0]
    cluster_indices = np.zeros(n)

    # Step 1: Start with a single cluster including all observations
    current_cluster = KMeans(n_clusters=1, n_init=10)
    current_cluster.fit(X)
    cluster_indices = current_cluster.labels_

    for i in range(1, k):
        best_sse = np.inf
        best_cluster_indices = None

        # Step 2: Bisecting - Divide the largest cluster into two sub-clusters using K-Means
        largest_cluster = np.argmax(np.bincount(cluster_indices))
        largest_cluster_indices = np.where(cluster_indices == largest_cluster)[0]
        largest_cluster_data = X[largest_cluster_indices]

        for _ in range(iter):
            kmeans = KMeans(n_clusters=2, n_init=10)
            kmeans.fit(largest_cluster_data)
            sub_cluster_indices = kmeans.labels_
            sse = kmeans.inertia_

            if sse < best_sse:
                best_sse = sse
                best_cluster_indices = sub_cluster_indices

        # Update cluster indices for the observations
        new_cluster_indices = np.copy(cluster_indices)
        largest_cluster_indices_to_update = largest_cluster_indices[best_cluster_indices == 1]
        new_cluster_indices[largest_cluster_indices_to_update] = i

        cluster_indices = new_cluster_indices

    return cluster_indices
