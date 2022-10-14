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
#define ll long long
using namespace std;
int main() {
	int n;
	ll a, b, x[105], y[105], r[105];
	ll Min = 1e18;
	double t;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i] >> r[i];
		t = double(sqrt(pow(x[i] - a, 2) + pow(y[i] - b, 2)) - r[i]);
		if (t < Min) {
			if(double(t) == (ll)t)	Min = t - 1;
			else	Min = (ll)t;
		}
	}
	cout << Min;
}

