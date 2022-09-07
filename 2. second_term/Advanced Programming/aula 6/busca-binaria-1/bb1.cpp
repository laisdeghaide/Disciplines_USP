#include <bits/stdc++.h>
using namespace std;

int main() {

    int t, n, test = 0;
    cin >> t;
    while(t--) {
        cin >> n;
        int vet[100001] = {};
        
        for(int i=1; i<=n; i++)
            cin >> vet[i];

        int k = 0, result;
        for(int i=1; i<=n; i++) {
            if(vet[i] - vet[i-1] > k)
                k = vet[i] - vet[i-1];
        }

        result = k;
        for(int i=1; i<=n; i++) {
            if(vet[i] - vet[i-1] == k)
                k--;
            else if(vet[i] - vet[i-1] > k) {
                result++;
                break;
            }
        }
        cout << "Case " << ++test << ": " << result << endl;
    }
    return 0;
}