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
#define int long long

const int N = 1e6 + 5;

vector <pair<int, int>> a[N];
int d[N], b[N];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector <array<int, 4>> edge;
	while (k--) {
		int x, y, w, h;
		cin >> x >> y >> w >> h;
		edge.push_back({y, x, x + w, 1});
		edge.push_back({y + h + 1, x, x + w, -1});
	}
	sort(edge.begin(), edge.end());
	int ans0 = 0, ans1 = 1e15, ans2 = -1;
	for(int i = 0; i < (int)edge.size(); ++i) {
		int y = edge[i][0], l = edge[i][1], r = edge[i][2], v = edge[i][3];
		for(int j = l; j <= r; ++j) b[j] += v;
		if (i == (int)edge.size() - 1 || y != edge[i + 1][0]) {
			int cnt = 0;

			int y2 = m + 1;
			if (i + 1 != (int)edge.size()) {
				y2 = edge[i + 1][0];
			}

			for(int j = 0; j < N; ++j) {
				cnt += (b[j] & 1);

				if (b[j] & 1) {
					ans1 = min(ans1, y * (n + 1) + j);
					ans2 = max(ans2, (y2 - 1) * (n + 1) + j);
				}
			}
			ans0 += (y2 - y) * cnt;
		}
	}
	if (ans0 == 0) ans1 = -1;
	cout << ans0 << " " << ans1 << " " << ans2;
}

