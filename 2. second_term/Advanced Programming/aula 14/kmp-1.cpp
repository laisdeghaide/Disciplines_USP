#include <bits/stdc++.h>
using namespace std;

char txt[100010], subtxt[100010];
vector<int>match_pos;
bool flag;

vector<int> compute_prefix(string p) {
    int m = p.size();
    vector<int> prefix(m+1);
    prefix[0] = 0;
    int k = 0;

    for(int i = 1; i < m; i++) {
        while(k > 0 && p[k] != p[i])
            k = prefix[k-1];
        
        if(p[k] == p[i])
            k++;
    }

    return prefix;
}

void KMP_matcher(string txt, string subtxt) {
    int n = txt.size();
    int m = subtxt.size();

    vector<int> Prefix = compute_prefix(subtxt);
    int q = 0;

    for(int i = 0; i < n; i++) {
        while(q > 0 && subtxt[q] != txt[i])
            q = Prefix[q-1];

        if(subtxt[q] == txt[i]) 
            q++;
        
        if(q == m) {
            flag = true;
            q = Prefix[q-1]; 
            break;
        }
    }

    return;
}

int main() {

    int t;
    cin >> t;
    
    while(t--) {
        cin >> txt;

        int q;
        cin >> q;

        while(q--) {
            flag = false;
            cin >> subtxt;

            KMP_matcher(txt, subtxt);

            if(flag) cout << "y" << endl;
            else cout << "n" << endl;
        }
    }

    return 0;
}