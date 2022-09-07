#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int path[404][404], used[404], dist[404];

int main()
{
    int n, m, u, v, d;
    string city1, city2, start;
    
    while (cin >> n >> m && n) {
        map<string, int> M;

        // pegando todas as estações
        for(int i=1; i<=n; i++) {
            cin >> city1;
            M[city1] = i;
        }

        // inicializando com um valor mt grande
        for(int i=1; i<=n; i++) {
            for(int j=i; j<=n; j++) {
                path[i][j] = INF;
                path[j][i] = INF;
            }
        }

        // pegando as conexões
        for(int i=1; i<=m; i++) {
            cin >> city1 >> city2 >> d;
            u = M[city1];
            v = M[city2];

            path[u][v] = d;
            path[v][u] = d;
        }

        // estação que o Peter vai iniciar
        cin >> start;
        int now = M[start], result = 0;

        // inicializando os vetores de distancia e usado
        for(int i=1; i<=n; i++) {
            dist[i] = INF;
            used[i] = 0;
        }

        dist[now] = 0;
        used[now] = 1;

        for(int i=2; i<=n; i++) {
            for(int j = 1; j<=n; j++) {
                if(!used[j] && dist[j] > path[now][j])
                    dist[j] = path[now][j];
            }

            int min = INF;
            for(int j=1; j<=n; j++) {
                if(!used[j] && dist[j] < min) {
                    min = dist[j];
                    now = j;
                }
            }

            if(dist[now] != INF) {
                result += dist[now];
                used[now] = 1;
            }
        }

        int count = 0;
        for(int i=1; i<=n; i++) 
            count += used[i];

        if(count == n) 
            cout << result << endl;
        
        else 
            cout << "Impossible" << endl;
    }

    return 0;
}