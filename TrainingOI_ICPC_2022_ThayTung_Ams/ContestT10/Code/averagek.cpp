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
long long a[100005];
int n;
long long k;
long long ans = 0;
map <long long, long long> mymap;
int main () {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] -= k;
	}
	long long sum = 0LL;
	mymap[sum] = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		if (mymap.find(sum) != mymap.end()) {
			ans = max(ans, (long long) i - mymap[sum]);
		}
		if (mymap.find(sum) == mymap.end()) {
			mymap[sum] = i;
		} else {
			mymap[sum] = min(mymap[sum], (long long) i);
		}
	}
	cout << ans;
	return 0;
}

