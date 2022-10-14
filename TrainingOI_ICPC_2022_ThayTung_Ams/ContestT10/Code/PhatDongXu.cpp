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

map <int, int> mymap;
int n, numQuery;
vector <int> save;

int main () {
	cin >> n >> numQuery;
	for (int query = 1; query <= numQuery; query++) {
		int l, r;
		std::cin >> l >> r;
		if (l <= r) {
			mymap[l]++;
			mymap[r + 1]--;
			save.push_back(l - 1);
			save.push_back(r);
		} else {
			mymap[1]++;
			mymap[r + 1]--;
			save.push_back(0);
			save.push_back(r);
			mymap[l]++;
			mymap[n + 1]--;
			save.push_back(l - 1);
			save.push_back(n);
		}
	}
	map <int, int>::iterator lastIT = mymap.begin();
	for (map <int, int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
		if (it != lastIT) {
			it->second += lastIT->second;
			lastIT = it;
		}
	}
	sort(save.begin(), save.end());
	int maxi = -1;
	for (int i = 0; i < (int) save.size() - 1; i++) {
		if (save[i] < save[i + 1]) {
			maxi = max(maxi, mymap[save[i] + 1]);
		}
	}
	cout << maxi << ' ';
	int ans = 0;
	for (int i = 0; i < (int) save.size() - 1; i++) {
		if (save[i] < save[i + 1] && maxi == mymap[save[i] + 1]) {
			ans += save[i + 1] - save[i];
		}
	}
	cout << ans;
	return 0;
}

