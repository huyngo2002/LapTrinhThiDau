#include <bits/stdc++.h>
using namespace std;
int n, sizeS;
struct GoiY
{
    string s;
    vector <int> pos;
};
vector <GoiY> v;
string ans = "";
set <int> kho;
set <int> :: iterator it;
int main ()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    while (n--)
    {
        GoiY x;
        cin >> x.s;
        int cnt;
        cin >> cnt;
        for (int i = 1, p; i <= cnt; i++)
        {
            cin >> p;
            x.pos.push_back(p - 1);
            sizeS = max (sizeS, p + (int)x.s.size() - 1);
        }
        v.push_back(x);
    }
    for (int i = 1; i <= sizeS; i++)
    {
        ans += 'a';
        kho.insert(i - 1);
    }
    for (int i = 0; i < (int)v.size(); i++)
    {
        for (int j = 0; j < (int)v[i].pos.size(); j++)
        {
            while (true)
            {
                it = kho.lower_bound(v[i].pos[j]);
                if (it != kho.end())
                {
                    if (*it - v[i].pos[j] < (int)v[i].s.size())
                    {
                        ans[*it] = v[i].s[*it - v[i].pos[j]];
                        kho.erase(it);
                    }
                               else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
