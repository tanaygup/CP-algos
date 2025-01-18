// HOW to solve
/*
    Number of ways to put 2 knights in k*k board is y = (k^2)(k^2 - 1)/2 -> as 1st knight has k2 boxes while 2nd knight has k2 - 1 boxes and we divide by 2 to avoid double counting

    now how many ways 2 knights can be placed in k*k board such that they are not attacking each other?
     = k2(k2-1)/2 - no. of ways they are attacking each other
    = y - x

    x = 2*3 block + 3*2 block and each block has 2 ways for attacking ie
    [*,x,x
      x,x,*]  &

      [ x,x,*
        *,x,x]

        now 2*3 blocks = (k-1) * (k-2) {k-1 for 2 and k-2 for 3} & 3*2 blocks = (k-2) * (k-1)
        x = 2 * (k-1)*(k-1) + 2* (k-2)*(k-1);
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll helper(ll k)
{
    ll y = (k * k) * (k * k - 1);
    y /= 2;

    ll x = 4 * (k - 1) * (k - 2);

    return y - x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cout << helper(i) << endl;
    }
}