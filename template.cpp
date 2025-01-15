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

template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

vll factors(int n)
{
    vll ans;
    int l = sqrt(n);
    for (int i = 1; i <= l; i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                ans.pb(i);
            else
            {
                ans.pb(i);
                ans.pb(n / i);
            }
        }
    }
    return ans;
}
string DecimalToBinary(ll num)
{
    string str;
    while (num)
    {
        if (num & 1)
            str.pb('1');
        else
            str.pb('0');
        num >>= 1;
    }
    return str;
}
ll BinaryToDecimal(string num)
{
    ll ans = 0;
    ll base = 1;
    for (int i = sz(num) - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            ans += base;
        base <<= 1;
    }
    return ans;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
} //__gcd
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
ll moduloMultiplication(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        b >>= 1;
    }
    return res;
}
ll powermod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
// Function to return the count of number of 1's at the ith bit in range [1, n]
long long getcount(long long n, int k)
{
    if (n <= 0)
        return 0;

    // Number of complete groups of 2^(k+1)
    long long group_size = 1LL << (k + 1);
    long long complete_groups = n / group_size;

    // Count `1`s contributed by complete groups
    long long res = complete_groups * (group_size / 2);

    // Count `1`s in the remainder group
    long long remainder = n % group_size;
    if (remainder > (1LL << k) - 1)
    {
        res += remainder - (1LL << k) + 1;
    }

    return res;
}

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (auto &it : a)
            cin >> it;
    }

    return 0;
}