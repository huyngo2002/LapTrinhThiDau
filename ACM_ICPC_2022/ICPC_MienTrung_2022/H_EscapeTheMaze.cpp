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
const int N=1e5+5, oo=2e9;
int n,m,k;
vector<int> adj[N];
vector<pa> them[N];
int d[N];
bool mini(int &a,int b) {
	if(a<=b) return 0;
	a=b;
	return 1;
}
void Dijkstra(int st) {
	priority_queue<pa,vector<pa>,greater<pa> > pq;
	for(int i=2; i<=n; i++) d[i]=oo;
	pq.emplace(0,st);
	while(!pq.empty()) {
		pa o=pq.top();
		pq.pop();
		if(o.fi!=d[o.se]) continue;
		for(auto i:adj[o.se])
			if(mini(d[i],o.fi+1)) pq.emplace(d[i],i);
		for(auto i:them[o.se]) {
			int time=max(i.se,o.fi);
			if(mini(d[i.fi],time+1)) pq.emplace(d[i.fi],i.fi);
		}
	}
}
int main() {
	cin>>n>>m;
	for(int i=1,u,v; i<=m; i++) {
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin>>k;
	for(int i=1,u,v,t; i<=k; i++) {
		cin>>t>>u>>v;
		them[u].emplace_back(v,t-1);
		them[v].emplace_back(u,t-1);
	}
	Dijkstra(1);
	cout<<(d[n]==oo?-1:d[n]);
	return 0;
}

