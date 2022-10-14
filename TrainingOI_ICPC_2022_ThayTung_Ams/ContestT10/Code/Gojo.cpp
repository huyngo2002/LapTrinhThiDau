/*
    Author: Nguyen Huy Ngo
    School: Ha Noi University of industry
*/
#include "bits/stdc++.h"
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
#define int long long
using ull = unsigned long long;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
const int N=5e5+5;
int n,m;
int a[N],b[N];
int res=0;
int l[N], r[N];
void minn(int c[]) {
	stack<int> st;
	for (int i=1; i<=m; i++) {
		while (!st.empty()&&c[i]<c[st.top()]) st.pop();
		l[i] = st.empty() ? 1 : st.top()+1;
		st.push(i);
	}
	stack<int> s;
	for (int i=m; i>=1; i--) {
		while (!s.empty()&&c[i]<=c[s.top()]) s.pop();
		r[i] = s.empty() ? m : s.top()-1;
		s.push(i);
	}
	for (int i=1; i<=m; i++) {
		res-=a[i]*(i-l[i]+1)*(r[i]-i+1);
	}
}
void maxx(int c[]) {
	stack<int> st;
	for (int i=1; i<=m; i++) {
		while (!st.empty()&&c[i]>c[st.top()]) st.pop();
		l[i] = st.empty() ? 1 : st.top()+1;
		st.push(i);
	}
	stack<int> s;
	for (int i=m; i>=1; i--) {
		while (!s.empty()&&c[i]>=c[s.top()]) s.pop();
		r[i] = s.empty() ? m : s.top()-1;
		s.push(i);
	}
	for (int i=1; i<=m; i++) {
		res+=a[i]*(i-l[i]+1)*(r[i]-i+1);
	}
}
int32_t main() {
	cin>>m;
	for (int i=1; i<=m; i++) cin>>a[i];
	minn(a);
	for (int i=1; i<=m; i++) l[i]=r[i]=0;
	maxx(a);
	cout << res;
}

