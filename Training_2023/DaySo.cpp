#include <bits/stdc++.h>
#define INF 1000000000000000000
#define maxn 200005
int n, a[100005];
long long s[100005];
using namespace std;
map<int, long long> getmin;
long long res = -INF;
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i){
		s[i] = s[i-1] + a[i];
		getmin[a[i]] = INF;
	}
	for (int i = 1; i <= n; ++i){
		if (getmin[a[i]] != INF){
			res = max(res, s[i] - getmin[a[i]]);
		}
		getmin[a[i]] = min(getmin[a[i]], s[i - 1]);
	}
	cout << res;
	return 0;
}
