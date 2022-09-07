#include <bits/stdc++.h>
using namespace std;

// checando se os recipientes (com c capacidade) enchem o container
bool fill_container(const vector<int> &vessels, int m, int capacity) {
    int remain_capacity = capacity;

    for(auto &milk : vessels) {

        //quantidade de leite ultrapassa a maxima capacidade
        if(milk > capacity)
            return false;

        if(milk > remain_capacity) {

            // todos os m containers estao cheios
            if(--m == 0)
                return false;
            
            // se não, atualiza a quantidade de leita que falta
            remain_capacity = capacity;
        }

        remain_capacity -= milk;
    }

    return true;
}

int main() {

    int m_containers, n_vessels, c;
    
    while(cin >> n_vessels >> m_containers) {
        vector<int> capacity_vessels;
        int low = 0, high = 0;

        for(int i=0; i<n_vessels; i++) {
            cin >> c;
            capacity_vessels.push_back(c);
            high += c;
        }

        while(low < high) {
            int mid = (low + high) / 2;

            if(fill_container(capacity_vessels, m_containers, mid))
                high = mid;

            else 
                low = mid + 1;
            
        }
        cout << low << endl;
    }
    return 0;
}