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
const ll MOD = 1e9 + 7;
const long double LOG9 = log(9);
const int N = 2e5 + 5;

ll ans = 0, pw[N];
long double lg[10];
string l, r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	pw[0] = 1;
	for (int i = 1; i < N; ++i) {
		pw[i] = pw[i - 1] * 9 % MOD;
	}

	for (int i = 1; i <= 9; ++i) {
		lg[i] = log(i);
	}

	cin >> l >> r;
	reverse(l.begin(), l.end());
	while (l.size() < r.size()) {
		l += "0";
	}
	reverse(l.begin(), l.end());

	if (l.size() > r.size() || (l > r)) {
		cout << "0\n";
		return 0;
	}

	ll cur = 1;
	int n = l.size();
	bool mark = true;
	long double sum = 0, mx = 0;
	for (int i = 0; i < n; ++i) {
		if (l[i] == r[i] && mark) {
			cur = cur * (l[i] - '0') % MOD;
			if (cur == 0) {
				break;
			}
			continue;
		}
		mark = false;

		int rr = r[i] - '0';
		if (rr == 0) {
			break;
		}

		{
			long double tmp = LOG9 * (n - i - 1);
			if (tmp > mx) {
				mx = tmp;
				ans = pw[n - i - 1];
			}
		}

		if (rr - 1 > 0) {
			long double tmp = sum + lg[rr - 1] + LOG9 * (n - i - 1);
			if (tmp > mx) {
				mx = tmp;
				ans = cur * (rr - 1) * pw[n - i - 1] % MOD;
			}
		}

		cur = cur * rr % MOD;
		sum += lg[rr];

		if (i == n - 1 && sum > mx) {
			ans = cur;
		}
	}

	if (l == r) {
		ans = cur;
	}

	cout << ans << '\n';

	return 0;
}


