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
const int N = 1e5 + 5;
int t, n, a[N];
int main () {
	cin >> t;
	while(t--) {
		cin >> n;
		int sum_1 = 0, sum = 0, best = -1e9 - 5, sum_2 = -1e9 - 5, cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum = max(a[i], sum + a[i]);
			best = max(sum, best);
			if (a[i] >= 0) {
				sum_1 += a[i];
				cnt++;
			}
			sum_2 = max(sum_2, a[i]);
		}
		if (cnt == 0) {
			sum_1 = sum_2;
		}
		cout << sum_1 << ' ' << best << endl;
	}
	return 0;
}

