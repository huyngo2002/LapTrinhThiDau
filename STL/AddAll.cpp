// Bài này dùng heap
// https://vjudge.net/problem/UVA-10954
#include <bits/stdc++.h>
int n;
const int MAX = 5005;
int a[MAX];
int main ()
{
    while (std::cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        std::priority_queue <int, std::vector <int>, std::greater <int>> heap_min;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
            heap_min.push(a[i]);
        }
        long long ans = 0;
        while (heap_min.size() > 1)
        {
            int min_1 = heap_min.top();
            heap_min.pop();
            int min_2 = heap_min.top();
            heap_min.pop();
            ans = ans + min_1 + min_2;
            heap_min.push(min_1 + min_2);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
