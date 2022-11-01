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



const int N = 1e4 + 4;

int n, m, p[N], par[N], cur[N], ans = 0, dp[N];
vector<int> group[N], ele[N];

int root(int v) {
	return (par[v] < 0) ? v : (par[v] = root(par[v]));
}

void join(int x, int y) {
	if ((x = root(x)) == (y = root(y))) return;
	if (par[x] > par[y]) swap(x, y);
	par[x] += par[y];
	par[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		par[i] = -1;
		cin >> p[i];
	}

	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		join(u, v);
	}

	for (int i = 1; i <= n; ++i) {
		group[root(i)].emplace_back(p[i]);
	}

	for (int i = 1; i <= n; ++i) {
		if (i == root(i)) {
			sort(group[i].rbegin(), group[i].rend());
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int x : group[root(i)]) {
			dp[x] = dp[x - 1] + 1;
		}
		for (int i = 1; i <= n; ++i) {
			dp[i] = max(dp[i], dp[i - 1]);
		}
	}
	cout << dp[n] << '\n';

	return 0;
}

