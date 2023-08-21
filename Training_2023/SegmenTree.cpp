#include <iostream>
#include <algorithm>
const int maxn = 1e5 + 1;
int n, m, a[maxn];
int T[4 * maxn], delta[4 * maxn];
void Init(int node, int L, int R){
	if (L == R){
		T[node] = a[L];
		return;	
	}
	int mid = (L + R) >> 1;
	Init(node * 2, L, mid);
	Init(node * 2 + 1, mid + 1, R);
	T[node] = std::min(T[node * 2], T[node * 2 + 1]);  
}
void Update(int node, int L, int R, int u, int v, int w){
	if (u > R || v < L) return;
	if (u <= L && v >= R){
		delta[node] += w;
		T[node] += w;
		return;
	}
	int mid = (L + R) >> 1;
	Update(node * 2, L, mid, u, v, w);
	Update(node * 2 + 1, mid + 1, R, u, v, w);
	T[node] = std::min(T[node * 2], T[node * 2 + 1]) + delta[node];
}
int GetMin(int node, int L, int R, int u, int v){
	if (u > R || v < L) return 1000000001;
	if (u <= L && v >= R) return T[node];
	int mid = (L + R) >> 1;
	int left = GetMin(node * 2, L, mid, u, v);
	int right = GetMin(node * 2 + 1, mid + 1, R, u, v);
	return std::min(left, right) + delta[node];
}
int main(){
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	Init(1, 1, n);
	for (int i = 1; i <= m; ++i){
		int type, u, v, w;
		std::cin >> type >> u >> v;
		if (type == 1){
			std::cin >> w;
			Update(1, 1, n, u, v, w);
		}
		else{
			std::cout << GetMin(1, 1, n, u, v) << '\n';
		}
	}
	return 0;
}
