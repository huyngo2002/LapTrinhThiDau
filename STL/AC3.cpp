// su dung heap
#include <bits/stdc++.h>
int numTest;
int n, k;
const int MAX = 100005;
struct segment
{
    int l, r;
    bool operator < (const segment& other)
    {
        return (this->l < other.l);
    }
};
int main()
{

    std::cin >> numTest;
    while (numTest--)
    {
        std::vector <segment> sg;
        std::cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            segment s;
            std::cin >> s.l >> s.r;
            sg.push_back(s);
        }
        sort(sg.begin(), sg.end());
        std::priority_queue <int, std::vector <int>, std::greater <int>> heap_min;
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            heap_min.push(sg[i].r);
        }
        ans = std::max (ans, heap_min.top() - sg[k - 1].l + 1);
        for (int i = k; i < n; i++)
        {
            heap_min.pop();
            heap_min.push(sg[i].r);
            ans = std::max (ans, heap_min.top() - sg[i].l + 1);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
