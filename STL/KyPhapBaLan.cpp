// https://www.spoj.com/problems/ONP/fbclid=IwAR3SEzTC-E9t1WsgwYSlFH2sdgakkYjDcMeluOfo1-wWFPgMFDt6D6hvubY
#include <bits/stdc++.h>
// stl: thu vien
// std: khong gian ten
int numTest;
int main()
{
    std::cin >> numTest;
    while(numTest--)
    {
        std::string s;
        std::cin >> s;
        std::stack <char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                std::cout << s[i];
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
            {
                st.push(s[i]);
            }
            if (s[i] == ')')
            {
                std::cout << st.top();
                st.pop();
            }
        }
        std::cout << std::endl;
    }
}
