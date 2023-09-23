#include <iostream>
#include <vector>
#include <algorithm>
int n, m, a[10000002], b[10000002];
std::vector<int> v;
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		std::cin >> a[i];
		v.push_back(a[i]);
	}	
	for (int i = 1; i <= m; ++i){
		std::cin >> b[i];
		v.push_back(b[i]);
	}
	std::sort(v.begin(), v.end());
	for (const auto& x : v) std::cout << x << ' ';
	return 0;
}
