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
typedef unsigned long long ll;
uint64_t mulmod(uint64_t a, uint64_t b, uint64_t n) {
    uint64_t r = 0;
    if ((a|b) < (1ULL << 32)) return (a*b) % n;
    if (a < b) { uint64_t t = a; a = b; b = t; }
    if (n <= (1ULL << 63)) {
        while (b > 0) {
            if (b & 1)  { r += a;  if (r >= n) r -= n; }
            b >>= 1;
            if (b)      { a += a;  if (a >= n) a -= n; }
        }
    } else {
        while (b > 0) {
            if (b & 1)  r = ((n-r) > a) ? r+a : r+a-n;    
            b >>= 1;
            if (b)      a = ((n-a) > a) ? a+a : a+a-n;    
        }
    }
    return r;
}
ll pow(ll a, ll d, ll n) {
	ll result = 1;
	a = a % n;
	while (d > 0) {
		if (d & 1) result = mulmod(result, a, n); 
		d >>= 1;
		a = mulmod(a, a, n);
	}
	return result;
}
pair<ll, ll> factor(ll n) {
	ll s = 0;
	while ((n & 1) == 0) {
		s++;
		n >>= 1;
	}
	return {s, n};
}
bool witness_test(ll s, ll d, ll n, ll witness) {
	if (n == witness) return true;
	ll p = pow(witness, d, n);
	if (p == 1) return true;
	for (; s > 0; s--) {
		if (p == n-1) return true;
		p = mulmod(p, p, n);
	}
	return false;
}
//2, 3, 5, 7, 11, 13, 17
bool miller(ll n) {
	if (n < 2) return false;
	if ((n & 1) == 0) return n == 2;
	ll s, d;
	tie(s, d) = factor(n-1);
	return witness_test(s, d, n, 2) && witness_test(s, d, n, 7) && witness_test(s, d, n, 3)
	       && witness_test(s, d, n, 5) && witness_test(s, d, n, 11) && witness_test(s, d, n, 13) && witness_test(s, d, n, 17);
}
int N;
string s;
int x[16];
vector<string> v;
int dem = 0;
void in() {
	string st = "";
	for (int i = 1; i <= N; i++) {
		if (x[i] == 1) {
			st += s[i-1];
		}
	}
	if (st.size() != 0)
		v.push_back(st);
}
void deQuy(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == N)
			in();
		else
			deQuy(i + 1);

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	N = s.size();
	deQuy(1);
	long long mx = -1;
	for(auto x : v) {
		long long k = stoull(x);
		if (miller(k))
			mx = max(mx, k);
	}
	cout << mx;
}

