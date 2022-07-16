//https://oj.vnoi.info/problem/mink
#include <bits/stdc++.h>
const int MAX = 17005;
int numTest, n, k;
int main()
{
    std::cin >> numTest;
    while (numTest--)
    {
        int a[MAX];
        std::cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
        }
        std::deque <int> dq;
        for (int i = 1; i <= k; i++)
        {
            while (!dq.empty() && dq.back() > a[i])
            {
                dq.pop_back();
            }
            dq.push_back(a[i]);
        }
        std::cout << dq.front() << ' ';
        for (int i = k + 1; i <= n; i++)
        {
            if (!dq.empty() && dq.front() == a[i - k])
            {
                dq.pop_front();
            }
            while (!dq.empty() && dq.back() > a[i])
            {
                dq.pop_back();
            }
            dq.push_back(a[i]);
            std::cout << dq.front() << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
