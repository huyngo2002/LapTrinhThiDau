/*
    Author: Nguyen Huy Ngo
    School: Ha Noi University of industry
*/
#include "bits/stdc++.h"
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
using ull = unsigned long long;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
const int MN = 2e5 + 5;
int tt;
ll n, a[MN];
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 1; i <= 2 * n; i++) {
			cin >> a[i];
		}
		ull x = 1, y = 1;
		for (int i = 1; i <= n; i++) {
			x *= a[i];
			y *= a[i+n];
			ull ucln = __gcd(x, y);
			x /= ucln;
			y /= ucln;
		}
		if (y == 1) {
			puts("finite");
		} else if (y == 0) {
			puts("repeating");
		} else {
			while (y % 2 == 0 && y != 1) {
				y /= 2;
			}
			while (y % 5 == 0 && y != 1) {
				y /= 5;
			}
			if (y == 1) {
				puts("finite");
			} else {
				puts("repeating");
			}
		}
	}
	return 0;
}

