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
#define fi first
#define se second
#define pb push_back
using ll = long long;
const int N = 1e5 + 5;
int n, a[N], k;
int main() {
	cin >> n >> k;
	int ans = 0;
	map<int, vector<int>> mp;
	map<int, vector<int>>::iterator it;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]].pb(i);
		a[i] *= a[i];
	}
	for (int i = 1; i <= n; i++) {
		int temp = k - a[i];
		it = mp.find(temp);
		if (it != mp.end()) {
			for (int j : it->second) {
				if (j <= i) {
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}

