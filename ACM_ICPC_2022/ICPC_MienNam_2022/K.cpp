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
vector<string> col = {"White", "Silver", "Gray", "Black", "Red", "Maroon", "Yellow", "Olive", "Lime", "Green", "Aqua", "Teal", "Blue", "Navy", "Fuchsia", "Purple"};
vector<int> x = {255, 192, 128, 0, 255, 128, 255, 128, 0, 0, 0, 0, 0, 0, 255, 128};
vector<int> y = {255, 192, 128, 0, 0, 0, 255, 128, 255, 128, 255, 128, 0, 0, 0, 0};
vector<int> z = {255, 192, 128, 0, 0, 0, 0, 0, 0, 0, 255, 128, 255, 128, 255, 128};
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, g, b;
	while (cin >> r >> g >> b) {
		if (r == -1) return 0;

		int dist = 999999999;
		int id = -1;
		for (int i = 0; i < 16; i++) {
			if ((r-x[i])*(r-x[i]) + (g-y[i])*(g-y[i]) + (b-z[i])*(b-z[i]) < dist) {
				dist = (r-x[i])*(r-x[i]) + (g-y[i])*(g-y[i]) + (b-z[i])*(b-z[i]);
				id = i;
			}
		}
		cout << col[id] << endl;
	}
	return 0;
}


