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