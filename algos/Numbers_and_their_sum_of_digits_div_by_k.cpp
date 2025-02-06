/*
    We have to find the numbers in the range [a,b] such that they are divisible by k and the sum of their digits are also divisible by k.
    a,b max is 2^31
    Now numbers in range div by k = (b/k) - (a/k);
    for the second part we use digit DP

    if k>90 then we can't have a number with digit sum divisible by k
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[10][2][90][90];

ll helper(int idx, string &s, bool flag, ll k, ll sum_mod, ll sum_dig_mod)
{
    if (idx == s.size())
    {

        if (sum_mod == 0 && sum_dig_mod == 0)
            return 1;
        return 0;
    }

    if (dp[idx][flag][sum_mod][sum_dig_mod] != -1)
        return dp[idx][flag][sum_mod][sum_dig_mod];

    ll till = (flag ? (s[idx] - '0') : 9);
    ll ans = 0;
    for (ll i = 0; i <= till; i++)
    {
        ans += helper(idx + 1, s, (flag && (i == till)), k, (sum_mod * 10 + i) % k, (sum_dig_mod + i) % k);
    }

    return dp[idx][flag][sum_mod][sum_dig_mod] = ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int c;
        string a, b;
        cin >> a >> b >> c;
        ll temp = stoi(a);
        temp--;
        string x = to_string(temp);

        if (c > 90)
        {
            cout << 0 << endl;
            continue;
        }

        memset(dp, -1, sizeof(dp));
        ll t1 = helper(0, b, true, c, 0, 0);
        memset(dp, -1, sizeof(dp));
        ll t2 = helper(0, x, true, c, 0, 0);

        cout << t1 - t2 << endl;
    }

    return 0;
}
