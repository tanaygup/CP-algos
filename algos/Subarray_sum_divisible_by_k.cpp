/*
    Here i am calculating number of subarrays whose sum is divisible by n(or any integer k)

    here the main concept used is that
    lets say a subarray 0...k ka sum mod n is P then if there exists any other subarray from k+1 to n whose sum mod n is P
    then it will be a valid subarray whose sum is divisible by n and we can add count of P to our answer.

    How??

    lets say S be sum of first subarray 0...k and T be sum of second subarray k+1...n
    S = nm + x and T = no + P
    then T-S = n(o-m) which is divisible by n
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (auto &it : a)
        cin >> it;

    ll ans = 0;
    unordered_map<ll, ll> mp;

    vector<ll> pref(n + 1);
    pref[0] = 0;
    mp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + a[i];
    }

    for (int i = 1; i < n + 1; i++)
    {
        pref[i] = (pref[i] % n + n) % n;

        if (mp.find(pref[i]) != mp.end())
        {
            ans += mp[pref[i]];
        }
        mp[pref[i]]++;
    }
    cout << ans << endl;
    return 0;
}
