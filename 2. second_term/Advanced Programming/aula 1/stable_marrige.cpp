#include <bits/stdc++.h>
using namespace std;


int prefer(int n, vector<vector<int>> &preferences, int w, int m, int m1) {
    for(int i=0; i<n; i++) {
        if(preferences[w][i] == m)
            return 1;
        
        else if(preferences[w][i] == m1)
            return 0;
    }

    return 0;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> preferences(2 * n, vector<int>(n + 1));
        vector<int> men(n, -1), women(n, -1);

        // preenchendo matriz de preferencias
        for(int row=0; row < 2*n; row++) {
            int idx, val;
            cin >> idx;
            for(int col=0; col < n; col++) {
                cin >> val;
                preferences[idx - 1 + (row < n ? 0 : n)][col] = val - 1;
            }
        }

        // qtd de homens casados
        int men_married = 0;

        // enquanto tiver homem solteiro
        while(men_married < n) {
            int m = 0;

            // encontrando algum homem solteiro
            for(; m < n; m++) {
                if(men[m] == -1)
                    break;
            }

            // encontrar a lista de preferencia dele
            for(int i=0; i < n && men[m] == -1; i++) {
                int w = preferences[m + n][i];

                // checa se mulher está solteira
                if(women[w] == -1) {
                    // se for, então casa com o homem
                    women[w] = m;

                    // atualiza na lista de homens que m não está mais solteiro
                    men[m] = 0;
                    men_married++;
                }
                
                else {
                    // se mulher prefere m a m'
                    int m1 = women[w];
                    if(prefer(n, preferences, w, m, m1)) {
                        women[w] = m;
                        men[m1] = -1;
                        men[m] = 0;
                    }
                }
            }
        }

        vector<pair<int, int>> ans;

        for(int i=0; i<n; i++)
            ans.push_back({women[i] + 1, i + 1});

        sort(ans.begin(), ans.end());
        
        // printando o resultado
        for(auto &curr : ans)
            cout << curr.first << " " << curr.second << endl;
    }

    return 0;
}