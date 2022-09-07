#include <bits/stdc++.h>
using namespace std;


int main() {

    string s;
    int ans = 0;

    while(getline(cin, s)) {
       for(int i = 0; i < int(s.length()); i++) {
           
           if(s[i] == '#') {
               cout << (ans == 0 ? "YES" : "NO") << endl;
               ans = 0;
           }

           else if(s[i] >= '0' && s[i] <= '9')
            ans = ((s[i] - '0') + (ans << 1)) % 131071;
       }
    }
    
    return 0;
}