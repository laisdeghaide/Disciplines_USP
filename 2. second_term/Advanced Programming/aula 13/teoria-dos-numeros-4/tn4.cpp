#include <bits/stdc++.h>
using namespace std;


int main() {

    int t, a, b;
    cin >> t;

    while(t--) { 
        cin >> a >> b;

        if(b % a == 0) {
            cout << a << " " << b << endl;
        }

        else {
            cout << -1 << endl;
        }
    }

    return 0;
}