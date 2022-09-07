#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 100000010
#define vi vector<int> 
#define MAXN 1010
#define endl '\n'

using namespace std;

int N, dp[MAXN][MAXN];
vi nums;

int solve(int i, int j)
{
    if (i > N) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    //Não escolhe o cara 'i' para a sequência crescente
    dp[i][j] = solve(i + 1, j);

    //Escolhe o cara 'i' para a sequência crescente
    if (nums[i] > nums[j])
        dp[i][j] = max(dp[i][j], 1 + solve(i + 1, i));

    return dp[i][j];
}


int main(int argc, char** argv)
{
    optimize;

    memset(dp, -1, sizeof dp);

    cin >> N;

    nums.resize(N + 1);

    nums[0] = -INF;

    for (int i = 1; i <= N; i++)
        cin >> nums[i];

    cout << N - solve(1, 0) << endl;

    return 0;
}
