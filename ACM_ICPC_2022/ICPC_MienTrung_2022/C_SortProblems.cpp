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
#define N 100005
#define int long long
#define pairii pair<int, int>
using namespace std;
int n,k;
int a[N];
int d[N], f[N][11];
void add(int &a, int b) {
	a+=b;
}
int get(int x) {
	int rs=0;
	while (x > 0)
		add(rs,d[x]), x-=x & (-x);
	return rs;
}
void update(int x, int val) {
	while (x <= n)
		add(d[x],val), x+=x & (-x);
}
signed main() {
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for (int i=1; i <= n; i++) {
		int pos;
		cin>>pos;
		cin>>a[pos];
		f[i][1]=1;
	}
	for (int len=2; len <= k; len++) {
		memset(d,0,sizeof d);
		for (int i=1; i <= n; i++)
			f[i][len]=get(a[i]-1), update(a[i],f[i][len-1]);
	}
	int res=0;
	for (int i=k; i <= n; i++)
		add(res,f[i][k]);
	cout<<res;
	return 0;
}


