#include <bits/stdc++.h>
using namespace std;
int t, n, k;
string s;
bool solve(string s, int n, int k)
{
    if (k <= 1)
    {
        map<char, int> mp;
    for (int i = 0; i < n; i++) mp[s[i]]++;
    vector<int> v;
    for (auto x : mp)
    {
        v.push_back(x.second);
    }
    sort(v.begin(), v.end());
    while (k > 1)
    {
        for (auto& x: v)
        {
            if (x % 2 != 0 && x > 0)
            {
                x--;
                k--;
            }
        }
    }
    int cnt = 0;
    for (auto x : v)
    {
        if (x % 2 != 0)
        {
            cnt++;
        }
    }
    if (cnt > k + 1) return false;
    if (cnt % 2 == 1 && k % 2 == 1) return true;
    if (cnt % 2 == 0 && k % 2 == 1) return false;
    if (cnt % 2 == 0 && k % 2 == 0) return true;
    if (cnt % 2 == 1 && k % 2 == 0) return true;
    }
    vector<int> count(26, 0);
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    int oddCount = 0;

    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount <= k && k <= n) {
        return true;
    }

    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cin >> s;
        if (solve(s, n, k))
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}
