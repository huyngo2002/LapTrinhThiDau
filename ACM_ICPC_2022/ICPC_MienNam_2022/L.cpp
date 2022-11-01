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
const int N = 1005;
const int oo = 1e9;

int n, f[N][2];
string a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}

		cin >> a >> b >> c;
		assert(a.size() == b.size());
		assert(a.size() == c.size());

		a = a + "0";
		b = b + "0";
		c = c + "0";

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		reverse(c.begin(), c.end());

		f[0][0] = 0;
		f[0][1] = oo;
		for (int i = 1; i <= n; ++i) {
			int aa = a[i] - '0';
			int bb = b[i] - '0';
			int cc = c[i] - '0';
			int sum = aa + bb;

			f[i][0] = f[i][1] = oo;
			f[i][0] = min(f[i][0], f[i - 1][0] + 1);
			f[i][1] = min(f[i][1], f[i - 1][1] + 1);

			if (sum == cc) {
				f[i][0] = min(f[i][0], f[i - 1][0]);
			}
			if (sum >= 10 && sum - 10 == cc) {
				f[i][1] = min(f[i][1], f[i - 1][0]);
			}
			if (sum + 1 == cc) {
				f[i][0] = min(f[i][0], f[i - 1][1]);
			}
			if (sum + 1 >= 10 && sum - 9 == cc) {
				f[i][1] = min(f[i][1], f[i - 1][1]);
			}
		}

		cout << f[n][0] << '\n';
	}

	return 0;
}
