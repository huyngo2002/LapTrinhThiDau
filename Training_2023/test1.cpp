#include <bits/stdc++.h>
using namespace std;
void stock_span(const vector<int>& ns) {
    int n = (int)ns.size();
    int a[n + 2];
    for (int i = 1; i <= n; i++)
        a[i] = ns[i - 1];
    std::stack <int> st2;
    std::vector <int> right;
    a[n + 1] = 0;
    st2.push(n + 1);
    for (int i = n; i >= 1; i--)
    {
        if (a[st2.top()] < a[i])
        {
            right.push_back(st2.top());
            st2.push(i);
        }
        else
        {
            while (a[st2.top()] >= a[i])
            {
                st2.pop();
            }
            right.push_back(st2.top());
            st2.push(i);
        }
    }
    std::stack <int> st1;

    std::vector <int> left;

    st1.push(0);
    for (int i = 1; i <= n; i++)
    {
        if (a[st1.top()] < a[i])
        {
            left.push_back(st1.top());
            st1.push(i);
        }
        else
        {
            while (a[st1.top()] >= a[i])
            {
                st1.pop();
            }
            left.push_back(st1.top());
            st1.push(i);
        }
    }
    //for (auto& x : right) x = (n - x >= 0 ? n - x : x - n);
    for (auto x : left) cout << x << ' ';
}

int main()
{
   // vector<int> ns = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ns = {10, 4, 5, 90, 120, 80};
        //for (auto x : ns) cout << x << ' ';
    stock_span(ns);

    return 0;
}
