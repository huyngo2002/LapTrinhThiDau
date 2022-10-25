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
const int N=2e5+5;
int t,n,k;
ll sum[N],f[2][N];
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>k;
		for(int i=1,x; i<=n; i++) cin>>x, sum[i]=sum[i-1]+x;
		for(int i=1; i<k; i++) f[0][i]=f[1][i]=0;
		for(int i=k; i<=n; i++) {
			ll tmp=sum[i]-sum[i-k];
			f[0][i]=max(f[0][i-1],f[1][i-k]+tmp);
			f[1][i]=max(f[1][i-1],f[0][i-k]-tmp);
		}
		cout<<max(f[0][n],f[1][n])<<'\n';
	}
	return 0;
}


