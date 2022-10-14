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
void ans(vector<int>& a) {
	int n=a.size();
	vector<int> A=a;
	map<int,int>mp;
	sort(a.begin(), a.end());
	for(int i=0; i<n; i++) {
		mp.insert({a[i],i});
	}
	for(int i=0; i<n; i++) {
		a[i]= mp[A[i]];
	}
	for (auto x : a) {
		cout << x << ' ';
	}
	cout << endl;
}
int32_t main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) {
		cin >> x;
	}
	ans(v);
	return 0;
}

