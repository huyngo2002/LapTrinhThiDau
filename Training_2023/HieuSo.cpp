#include <iostream>
#include <algorithm>
int n;
long long  a[1000005], mx = 1e18 + 7, ans = -1e18 - 7;
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	for (int i = 1; i <= n; ++i){
		mx = std::min(mx, a[i]);
		ans = std::max(ans, a[i] - mx);
	}
	std::cout << ans;
	return 0;
}
