// Link: https://oj.vnoi.info/problem/icpc21_mb_b
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n, a[100005], sum = 0;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
		sum+=a[i];
	}
	cout<<-sum;
}
