//https://open.kattis.com/problems/alicedigital
#include <bits/stdc++.h>
int n, m, numTest;
const int MAX = 100005;
int a[MAX];
int main()
{
    std::cin >> numTest;
    while(numTest--)
    {
        std::vector <int> pos; // lưu lại các vị trí có giá trị bằng m
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
            if (a[i] == m)
            {
                pos.push_back(i);
            }
        }
        long long ans = -1e9;
        for (auto x : pos)
        {
            long long sum = a[x];
            int left = x - 1;
            while(a[left] > a[x] && left >= 1)
            {
                sum += a[left];
                left--;
            }
            int right = x + 1;
            while(a[right] > a[x] && right <= n)
            {
                sum += a[right];
                right++;
            }
            ans = std::max (ans, sum);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
