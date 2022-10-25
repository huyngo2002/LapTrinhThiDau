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
#define pa pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+2;
int n,q,a[N];
int l[N],r[N];
int lc[N],rc[N],dif[N],all[N],BIT[N];
vector<pa> v[N];
bool check() {
	for(int i=0; i<=n; i++) v[i].clear();
	memset(BIT,0,sizeof(BIT));
	bool ok=0;
	for(int i=1; i<=q; i++) if(lc[i]<=rc[i]) {
			ok=1;
			int mid=(lc[i]+rc[i])/2;
			v[l[i]-1].emplace_back(-i,mid);
			v[r[i]].emplace_back(i,mid);
		}
	return ok;
}
void update(int x) {
	for(int i=x; i<N; i+=i&-i) ++BIT[i];
}
int get(int x) {
	int sum=0;
	for(int i=x-1; i; i^=i&-i) sum+=BIT[i];
	return sum;
}
int main() {
	cin>>n>>q;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=q; i++) {
		cin>>l[i]>>r[i];
		lc[i]=1, rc[i]=N-2, dif[i]=(r[i]-l[i]+2)/2;
	}
	while(check()) {
		for(int i=1; i<=n; i++) {
			update(a[i]);
			for(auto x:v[i])
				if(x.fi<0) all[-x.fi]=-get(x.se);
				else {
					if(all[x.fi]+get(x.se)>=dif[x.fi]) rc[x.fi]=--x.se;
					else lc[x.fi]=++x.se;
				}
		}
	}
	for(int i=1; i<=q; i++) cout<<lc[i]-1<<'\n';
	return 0;
}

