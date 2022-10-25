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
#define REP(i, a, b) \
	for (int i = int(a); i <= int(b); i++)
#define TRvi(c, it) \
	for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
	for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
const int N = 1e5 + 5;
int a[N];
string s;
int z[N];
int cnt[N];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	int n = s.size();
	int l = 0;
	int r = 0;
	for(int i = 1; i < n; i++) {
		if(i <= r) z[i] = min(z[i-l],r-i+1);
		while(i + z[i] < n && s[z[i]] == s[z[i]+i]) z[i]++;
		if(i + z[i] - 1 > r) {
			r = i + z[i] - 1;
			l = i;
		}
		cnt[z[i]]++;
	}
	for(int i = n; i >= 1; i--)
		cnt[i] += cnt[i+1];
	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		if(cnt[x] >= 2 && z[n-x] == x) {
			cout << "YES " << cnt[x] + 1 << '\n';
		} else cout << "NO\n";
	}
}


