#include <bits/stdc++.h>
using namespace std;

void password(int pos, string& rule, vector<string>& input, string& output){
    if(pos == rule.length()){
        cout << output << endl;
        return;
    }

    if(rule[pos] == '0'){
        
        for(int i=0; i<10; i++){
            output += (i + '0');
            password(pos+1, rule, input, output);
            output.pop_back();
        }

    }
    else {
        int len = output.length();
        for(auto& w : input){
            output += w;
            password(pos+1, rule, input, output);
            output.resize(len);
        }
    }
}

int main()
{
    int n;
    string word;

    while(cin >> n){
        vector<string> words;

        for(int i=0; i<n; i++){
            cin >> word;
            words.push_back(word);
        }

        int m;
        cin >> m;
        string rule;

        cout << "--" << endl;

        for(int i=0; i<m; i++){
            cin >> rule;
            string output = "";
            password(0, rule, words, output);
        }
    }

    return 0;
}