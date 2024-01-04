#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int mov(char a, char b)
{
    if (a == b) return 0;
    if (a == '0' && b != '0') return 10 - (b - '0');
    if (b == '0' && a != '0') return 10 - (a - '0');
    return abs((a - '0') - (b - '0'));
}
int solve(string s)
{
    int ans = 4;
    if (s[0] == '0') ans += 9;
    if (s[0] != '0') ans += (s[0] - '0' - 1);

    ans += mov(s[0], s[1]);
    ans += mov(s[1], s[2]);
    ans += mov(s[2], s[3]);
    return ans;
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        cout << solve(s) << '\n';
    }
    return 0;
}
