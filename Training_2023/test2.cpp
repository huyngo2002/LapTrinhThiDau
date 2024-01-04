//https://cses.fi/problemset/task/1142/
#include <bits/stdc++.h>
using namespace std;
int n;
const int MAX = 200005;
long long a[MAX];
int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::stack <int> st1;
    std::stack <int> st2;
    std::vector <int> left;
    std::vector <int> right;
    st1.push(0);
    for (int i = 1; i <= n; i++)
    {
        if (a[st1.top()] <= a[i])
        {
            left.push_back(st1.top());
            st1.push(i);
        }
        else
        {
            while (a[st1.top()] > a[i])
            {
                st1.pop();
            }
            left.push_back(st1.top());
            st1.push(i);
        }
    }
    a[n + 1] = 0;
    st2.push(n + 1);
    for (int i = n; i >= 1; i--)
    {
        if (a[st2.top()] <= a[i])
        {
            right.push_back(st2.top());
            st2.push(i);
        }
        else
        {
            while (a[st2.top()] > a[i])
            {
                st2.pop();
            }
            right.push_back(st2.top());
            st2.push(i);
        }
    }
    reverse(right.begin(), right.end());
    for (auto x : left) cout << x << ' ';
    cout << '\n';
    for (auto x : right) cout << x << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        cout <<  (right[i] - left[i] - 1) << ' ';
    }
    /*long long ans = -1e9;
    for (int i = 0; i < n; i++)
    {
        ans = std::max (ans, a[i + 1] * (right[i] - left[i] - 1));
    }
    std::cout << ans;*/
    return 0;
}
