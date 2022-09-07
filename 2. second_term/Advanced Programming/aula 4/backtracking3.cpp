#include <bits/stdc++.h>
using namespace std;


string initial_config, target_config;
map<string, int> paths;

int moves[8][4] = {1, 0, 0, 0,
				  -1, 0, 0, 0,
				   0, 1, 0, 0,
				   0, -1, 0, 0,
                   0, 0, 1, 0,
                   0 ,0, -1, 0,
                   0, 0, 0, 1,
                   0, 0, 0, -1};


int BFS() {
    // case when initial state is equal the target
    if(initial_config == target_config)
        return 0;

    // case when the target state is forbidden
    if(paths[target_config] == -1) 
        return -1;

    queue<pair<string, int>> q;
    q.push(make_pair(initial_config, 1));

    // while there's elements
    while (!q.empty()){ 
		
		pair<string, int> config = q.front();
        q.pop(); 

        // check if is the end
		if (config.first == target_config)
			return config.second;

        // for all possible movements 
        for (int i=0; i<8; i++){
			string temp = config.first;
			
            // adding to the state
            for(int j=0; j<4; j++) {
                temp[j] += moves[i][j];
                if(temp[j] < '0')
                    temp[j] = '9';
                else if(temp[j] > '9')
                    temp[j] = '0';
            }

            int n = paths[temp];
            if(n != 0) 
                continue;
            
            if(temp == target_config)
                return config.second;

            paths[temp] = config.second + 1;
            n = config.second + 1;
            q.push(make_pair(temp, n));
		}
    }

    return -1;
}


int main()
{
    int n, n_forbidden;
    char c;
    cin >> n;

    while(n--) {

        // initial state
        for(int i=0; i<4; i++) {
            cin >> c;
            initial_config += c;
        }

        // target state
        for(int i=0; i<4; i++) {
            cin >> c;
            target_config += c;
        }

        cin >> n_forbidden;
        
        // marking all forbbiden states with -1
        for(int i=0; i<n_forbidden; i++) {
            string temp = "";
            for(int j=0; j<4; j++) {
                cin >> c;
                temp += c;
            }
            paths[temp] = -1;
        }

        cout << BFS() << endl;
    }
   
    return 0;
}