#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

const ld pi = acos(-1);
const ll MOD = 1000000007;
const ll N = 1e5 + 7;

typedef vector<long long> vll;
#define pb push_back
#define sz(x) ((int)(x).size())

void helper(ll n, vector<pair<ll, ll>> &ans, ll i, ll j, ll k)
{
    if (n == 1)
    {
        ans.pb({i, k});
        return;
    }

    helper(n - 1, ans, i, k, j);
    ans.pb({i, k});
    helper(n - 1, ans, j, i, k);

    // return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> ans;
    ll i = 1, j = 2, k = 3;
    helper(n, ans, i, j, k);

    cout << ans.size() << endl;
    for (auto &it : ans)
    {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}