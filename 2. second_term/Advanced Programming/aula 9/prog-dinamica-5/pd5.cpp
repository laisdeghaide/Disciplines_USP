#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;

int N;
vi nums;

int solve()
{
    vi lis;

    for (auto curr : nums)
    {
        auto it = upper_bound(ALL(lis), curr);

        if (it == lis.end())
            lis.PB(curr);
        else
            (*it) = curr;
    }

    return N - lis.size();
}


int main(int argc, char** argv)
{
    optimize;

    cin >> N;

    nums.resize(N);

    for (auto &curr : nums)
        cin >> curr;

    cout << solve() << endl;

    return 0;
}
