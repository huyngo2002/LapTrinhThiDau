// Link: https://oj.vnoi.info/problem/olp_ct20_vca
#include<bits/stdc++.h>
using namespace std;
template<typename T> void minimize(T &res, const T &val) { if (res > val) res = val; }
int cnt[256];
int main()
{
    int k;
    string s;
    cin >> k >> s;

    int res = 0x3f3f3f3f;
    memset(cnt, 0, sizeof(cnt));
    for (int l = 0, r = -1; l < s.size(); --cnt[s[l++]])
    {
        while (r + 1 < s.size() && (cnt['A'] < k || cnt['V'] < k || cnt['C'] < k)) ++cnt[s[++r]];
        if (cnt['A'] < k || cnt['V'] < k || cnt['C'] < k) break;

        int t = 0;
        t += cnt['A'] - k;
        t += cnt['V'] - k;
        t += cnt['C'] - k;
        minimize(res, t);
    }

    cout << res;
    return 0;
}
