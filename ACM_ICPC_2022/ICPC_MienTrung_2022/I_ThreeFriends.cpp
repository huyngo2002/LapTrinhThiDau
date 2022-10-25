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
#define REP(i, a, b) \
	for (int i = int(a); i <= int(b); i++)
#define TRvi(c, it) \
	for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
	for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef int64_t i64;
i64 C(i64 n, int k) {
	if(!k) return 1;
	if(k>n) return 0;

	if(k==1) return n;
	if(k==2) return n*(n-1)/2;
	return n*(n-1)*(n-2)/6;
}
void solve() {
	int n;
	cin >> n;
	vector <i64> cnt(5, 0);
	i64 x;
	for(int i=1; i<=n; ++i) {
		cin >> x;
		cnt[x%5]++;
	}
	i64 ans=0;
	for(int i=0; i<5; ++i) {
		for(int j=i; j<5; ++j) {
			for(int k=j; k<5; ++k) {
				if((i+j+k)%5) continue;
				if(i==j) {
					if(j==k) ans+=C(cnt[i], 3);
					else ans+=C(cnt[i], 2)*C(cnt[k], 1);
				}

				else {
					if(j==k) ans+=C(cnt[j], 2)*C(cnt[i], 1);
					else ans+=cnt[i]*cnt[j]*cnt[k];
				}
			}
		}
	}

	cout << ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	while(t--) solve();
}


