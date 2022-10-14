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
int a[100005];
int n, m;
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1;
	int r = a[n];
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int lastPos = 1;
		int cnt = 1;
		for (int i = 2; i <= n; i++) {
			if (a[i] - a[lastPos] >= mid) {
				lastPos = i;
				cnt++;
			}
		}
		if (cnt >= m) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}

