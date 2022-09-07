#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

bool is_prime(int n) {
    for(int i = 2; i < n; i++) {
        if(n % i == 0)
            return false;
    }

    return true;
}

void sieve(int n) {
    for(int i = 2; i < n; i++) {
        if(is_prime(i))
            primes.push_back(i);
    }
}

int get_powers(unsigned int divider, int p) {
    int res = 0;

    for(unsigned int power = p; power <= divider; power *= p)
        res += divider / power;

    return res;
}
 
bool divides_factorial(int divider, int factorial) {
    if(factorial == 0)
        return false;

    else if(divider >= factorial)
        return true;

    else {
        unsigned int k = factorial;
        vector<pair<int, int>> factors;

        for(int i = 0; i < primes.size(); i++) {
            if(primes[i] > k)
                break;
            
            else {
                pair<int, int> f = {primes[i], 0};

                while(k % primes[i] == 0) {
                    f.second ++;

                    k /= primes[i];
                }

                if(f.second) 
                    factors.push_back(f);
            }
        }

        if(k > 1) {
            if(divider < k) 
                return false;
            
            else 
                factors.push_back(pair<int,int>(k, 1));
        }

        for(int i = 0; i < factors.size(); i++) {
            if(factors[i].second - get_powers(divider, factors[i].first) > 0)
                return false;
        }

        return true;
    }
}


int main() {

    sieve(50000);
    unsigned int factorial, divider;


    while(cin >> factorial >> divider) {
        if(divides_factorial(divider, factorial))
            cout << divider << " divides " << factorial << "!" << endl;
        
        else 
            cout << divider << " does not divide " << factorial << "!" << endl;
    }

    return 0;
}