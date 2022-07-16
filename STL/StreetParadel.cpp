// https://www.spoj.com/problems/STPAR/fbclid=IwAR0-HMqRUru3nSlYGWPi_vX8Lfpw7UqdE2-V0zVYvw352cyJzUtn3EX-SvM
#include <bits/stdc++.h>
int n;
const int MAX = 1005;
int a[MAX];
int main()
{
    while(std::cin >> n)
    {
        std::stack <int> st;
        if (n == 0)
        {
            break;
        }
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
        }
        int p = 1;
        for (int i = 1; i <= n; i++)
        {
            while (!st.empty() && st.top() == p)
            {
                st.pop();
                p++;
            }
            if (a[i] == p)
            {
                p++;
            }
            else
            {
                st.push(a[i]);
            }
        }
        while (!st.empty() && st.top() == p)
        {
            st.pop();
            p++;
        }
        std::cout << (p == n + 1 ? "yes" : "no") << std::endl;
    }
    return 0;
}
