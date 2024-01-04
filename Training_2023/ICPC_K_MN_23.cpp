#include <iostream>
const int MAX = 1e5 + 5;
int a[MAX], b[MAX], c[MAX], n, ans = 1;
int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        if (a[i] > b[i - 1])
        {
            b[i] = b[i - 1] + 1;
            continue;
        }
        b[i] = (b[i - 1] < a[i] ? b[i - 1] : a[i]);
    }
    for (int i = n; i >= 1; --i)
    {
        if (a[i] > c[i + 1])
        {
            c[i] = c[i + 1] + 1;
            continue;
        }
        c[i] = (c[i + 1] < a[i] ? c[i + 1] : a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        ans = (ans > ((b[i] < c[i] ? b[i] : c[i]))? ans : ((b[i] < c[i] ? b[i] : c[i])));
    }
    std::cout << ans;
    return 0;
}
