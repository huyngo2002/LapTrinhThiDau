/*
    Author: Nguyen Huy Ngo
    School: Ha Noi University of industry
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
using namespace std;
#pragma GCC optimize("Ofast")
#define int long long
int count(string s, int K)
{
    int N = s.length();
    int res = 0;
    int countOne = 0;
    int freq[N + 1] = {0};
    freq[0] = 1;
    for (int i = 0; i < N; i++) {
        countOne += (s[i] - '0');
        if (countOne >= K) {
            res += freq[countOne - K];
        }
        freq[countOne]++;
    }
    return res;
}
int32_t main()
{
    string s;
    int K;
    cin >> K;
    cin >> s;
    int ans = count(s, K);
    cout << ans;
    return 0;
}

