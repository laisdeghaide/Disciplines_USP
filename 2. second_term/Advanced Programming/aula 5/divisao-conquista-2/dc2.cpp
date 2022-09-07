#include <bits/stdc++.h>
using namespace std;

int rec(set<pair<int,int>> &C, int vet[], int i, int j) {
    if(i > j)
        return 0;

    set<pair<int,int>> C1;

    // pegando o menor valor da janela que estou olhando
    auto it = C.begin();
    pair<int,int> val;
    val = *it;
    int a3 = val.first * (j-i+1);
    int k = val.second;
    C.erase(val);

    // para não criar dois sets novos, eu remanejo o meu set principal (tiro os elementos dele e insiro em um novo) 
    for(int z=i; z<k; z++) {
        C.erase({vet[z], z});
        C1.insert({vet[z], z});
    }

    int a1 = rec(C1, vet, i, k-1);
    int a2 = rec(C, vet, k+1, j);

    return max(a3, max(a1, a2));
}

int main() {
    int n;
    cin >> n;
    int vet[n];
    set<pair<int,int>> s;

    for(int i=0;i<n;i++) {
        cin >> vet[i];
        s.insert({vet[i], i});
    }

    int result = rec(s, vet, 0, n-1);

    cout << result << endl;
    
    return 0;
}