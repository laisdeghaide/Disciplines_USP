#include <bits/stdc++.h>
using namespace std;


int main() {

    int t, n;

    cin >> t;

    while(t--) {
        cin >> n;
        vector<int> result;

        if(n == 1) {
            cout << 1 << endl;
            continue;
        }

        if(n == 0) {
            cout << 0 << endl;
            continue;
        }

        for(int i = 9; i > 1; i--) {
            while(n % i == 0) {
                result.push_back(i);
                n /= i;
            }
        }

        if(n > 9)
            cout << -1 << endl;

        else {
            sort(result.begin(), result.end());

            for(int i = 0; i < int(result.size()); i++) 
                cout << result[i];
            
            cout << endl;
        }
    }
    
    return 0;
}