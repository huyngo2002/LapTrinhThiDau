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
const long long mod = 1000000007;
long long fact[100005], invFact[100005];
string s;
int n, k;
long long power(const long long x, long long n) {
	if (n == 0) {
		return 1LL;
	}
	long long ret = power(x, n >> 1);
	(ret *= ret) %= mod;
	if (n % 2 == 1) {
		(ret *= x) %= mod;
	}
	return ret;
}

long long C(int k, int n) {
	long long ret = fact[n];
	(ret *= invFact[k]) %= mod;
	(ret *= invFact[n - k]) %= mod;
	return ret;
}
long long a[1005], ans = 0;
int main () {
	cin >> n >> k;
	set<long long> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	int m = s.size();
	fact[0] = 1LL;
	invFact[0] = 1LL;
	for (int i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * (long long) i) % mod;
		invFact[i] = power(fact[i], mod - 2);
	}
	if (m < k)
		ans = C(m, k);
	else
		ans = C(k, n);
	cout << ans;
	return 0;
}

