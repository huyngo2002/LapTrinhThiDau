#include <iostream>
int main() {
	int n, a[100002], ans = -1e9, _min = 1e9;
	std::cin >> n;
	for (int i = 1; i <= n; ++i){
		std::cin >> a[i];
		_min = (_min < a[i] ? _min : a[i]);
		ans = (ans > (a[i] - _min) ? ans : a[i] - _min);
	}
	std::cout << ans;
	return 0;
}
