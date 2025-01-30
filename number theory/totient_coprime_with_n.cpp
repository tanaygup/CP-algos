/*
    given n;
    find in range [1,n] how many are coprime with n
*/

#include <bits/stdc++.h>
using namespace std;

long long totient(long long n)
{
    long long res = n;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

int main()
{
    long long n;
    cin >> n;
    cout << totient(n);
}