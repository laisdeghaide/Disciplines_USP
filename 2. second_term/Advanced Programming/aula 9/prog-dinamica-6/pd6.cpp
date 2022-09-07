#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s1, s2;
    
    while (getline(cin, s1)) {
        getline(cin, s2);
        int s1_size = s1.size();
        int s2_size = s2.size();

        int ms[s1_size+1][s2_size+1], maxi = 0;

        for(int i=0; i<=s1_size; i++) {
            for(int j=0; j<=s2_size; j++) {
                if(i == 0 || j == 0)
                    ms[i][j] = 0;

                else if(s1[i-1] == s2[j-1])
                    ms[i][j] = 1 + ms[i-1][j-1];

                else 
                    ms[i][j] = max(ms[i-1][j], ms[i][j-1]);
                
                if(ms[i][j] > maxi)
                    maxi = ms[i][j];
            }
        }

        cout << maxi << endl;
    }

    return 0;
}