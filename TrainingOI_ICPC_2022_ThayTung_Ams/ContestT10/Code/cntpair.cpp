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
using ll = long long;
const int MN = 1e5;
ll a[MN];
int n;
int main() {
	cin >> n;
	int cnt_c = 0, cnt_l = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			cnt_c++;
		}
	}
	cnt_l = n - cnt_c;
	ll ans = 0;
	ans = 1LL * cnt_l * (cnt_l - 1) / 2 + 1LL * cnt_c * (cnt_c - 1) / 2;
	cout << ans << endl;
	return 0;
}

