#include <bits/stdc++.h>
using namespace std;

#define M 25001 //maximum share of each person, max coin is 500c and max number of coins is 100

bool MEMO[M]; 

int main()
{
    int i, j, t, m, target, sum, coins[101];
    
    //cin number of problems
    cin >> t;

    while(t--) {
        //cin number of coins 
        cin >> m; 
		sum = 0;
        //cin the coins and calculate their sum
        for(i = 1; i <= m; i++) {
            cin >> coins[i];
            sum += coins[i];
        }

       //the share of each person (minus one if sum is odd)
        target = sum / 2;
        memset(MEMO, 0, sizeof(MEMO));
        MEMO[0] = true;


        for(i = 1; i <= m; i++)
            for(j = target; j >= 1; j--)
                //if element j in the v table is false see if it could be reached or no//if its true leave it
                if(!MEMO[j])
                    MEMO[j] = (coins[i] <= j)? MEMO[j-coins[i]] :false; 

         //see which is the last element that can be reached within the rangeof the share of each person
        for(j = target; j >= 1; j--)
            if(MEMO[j])
                break;

        //the rest is the difference between total money and total shares
        cout << (sum - j * 2) <<endl;
    }

    return 0;
}