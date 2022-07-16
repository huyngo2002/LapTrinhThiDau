#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t;
ll n, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> t;
	int num = 1;
	while (t--){
		cout << "Case #" << num << ": ";
		num++;
		cin >> n >> k;
		priority_queue <ll> pq;
		map <ll, ll> m;
		m[n] = 1;
		pq.push(n);
		while (!pq.empty()){
			ll top = pq.top();
			pq.pop();
			ll h1 = (top - 1) / 2;
			if (m.find(h1) == m.end()){
				pq.push(h1);
			}
			m[h1] += m[top];
			ll h2 = top - h1 - 1;
			if (m.find(h2) == m.end()){
				pq.push(h2);
			}
			m[h2] += m[top];
			if (k <= m[top]){
				cout << max(h1, h2) << ' ' << min(h1, h2) << endl;
				break;
			}
			else{
				k = k - m[top];
			}
		}
	}
    return 0;
}

