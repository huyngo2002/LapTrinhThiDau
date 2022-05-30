//Link: https://oj.vnoi.info/problem/olp_kc19_cow
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	int n; 
	ll a, b, x[105], y[105], r[105];
	ll Min = 9999999999;
	double t;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++){
		cin >> x[i] >> y[i] >> r[i];
		t = double(sqrt(pow(x[i] - a, 2) + pow(y[i] - b, 2)) - r[i]);
		if (t < Min){
			if(double(t) == (ll)t)	Min = t -1;
			else	Min = (ll)t;
		}
	}
	cout << Min;
}
