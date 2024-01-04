#include <bits/stdc++.h>
const int MAX = 1e5;
bool isPrime[MAX + 2];
int n, a[MAX];
void sieve()
{
    memset(isPrime, 1, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX; ++i)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
int f[MAX];
int main()
{
    sieve();
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }
    f[1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = -5; j <= 5 && j != 0; ++j)
        {
            if (isPrime[a[i] - a[i + j] && (i + j) >= 1 && (i + j) <= n)
            {
                f[i] = std::max(f[i], f[i + j] + 1);
            }
        }
    }
    return 0;
}
/*
- gọi f[i] là dãy dài nhất tính đến vị trí i

*/
