// set
// https://www.hackerrank.com/challenges/minimum-loss/problem
#include <bits/stdc++.h>
int n;
std::set <long long> s;
const int MAX = 200005;
long long a[MAX];
int main ()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    long long ans = 0xffffffff;
    s.insert(a[1]);
    for (int i = 2; i <= n; i++)
    {
        s.insert(a[i]);
        if (s.upper_bound(a[i]) != s.end())
        {
            ans = std::min(ans, *s.upper_bound(a[i]) - a[i]);
        }
    }
    std::cout << ans;
    return 0;
}
