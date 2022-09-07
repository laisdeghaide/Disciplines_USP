#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> jobs;
        int acc = 0;
        int result = 0;

        for(int i=0; i<n; i++) {
            int duration, weight;
            cin >> duration;
            cin >> weight; 
            jobs.push_back(make_pair(duration, weight));
        }

        sort(jobs.begin(), jobs.end(), [](auto &job1, auto &job2) {
            return ((job1.first * job2.second) < (job2.first * job1.second));
        });

        for(auto x:jobs) {
            acc += x.first;
            result += acc * x.second;
        }

        cout << result << endl;
    }

    return 0;
}