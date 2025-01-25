/*
    no of zeroes are equal to
    sigma (n/5^i);
*/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

const ld pi = acos(-1);
const ll MOD = 1000000007;
const ll N = 1e5 + 7;

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    ll cnt = 0;
    for (ll i = 5; (n / i) >= 1; i = 5 * i)
    {
        cnt += (n / i);
    }
    cout << cnt;

    return 0;
}