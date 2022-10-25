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
const int N=102, MOD=1e9+7;
int n,m,k;
int p[12],a[N][N];
int f[10][N][N];
void add(int &a,int b) {
	a+=b;
	if(a>=MOD) a-=MOD;
}
int sum_rec(int x1,int y1,int x2,int y2) {
	return a[x2][y2]+a[x1-1][y1-1]-a[x2][y1-1]-a[x1-1][y2];
}
int main() {
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) cin>>a[i][j], a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	for(int _=1; _<=k; _++) cin>>p[_];
	f[0][1][1]=1;
	for(int _=1,val; _<k; _++) {
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++) if(f[_-1][i][j]) {
					val=f[_-1][i][j];
					for(int k=i; k<n; k++) {
						if(sum_rec(i,j,k,m)>p[_]) break;
						add(f[_][k+1][j],val);
					}
					for(int k=j; k<m; k++) {
						if(sum_rec(i,j,n,k)>p[_]) break;
						add(f[_][i][k+1],val);
					}
				}
	}
	int ans=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(f[k-1][i][j]&&sum_rec(i,j,n,m)<=p[k]) add(ans,f[k-1][i][j]);
	cout<<ans;
	return 0;
}


