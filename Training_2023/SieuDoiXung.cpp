#include <iostream>
#include <set>
#include <algorithm>
std::set<long long> v;
long long x, n;
void init() {
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 17; ++j){
			n = 0;
			for (int k = 1; k <= j; ++k){
				n = n * 10 + i;
				v.insert(n);
			}
		}
	}
}
int main() {
	std::cin >> x;
	init();
	std::cout << *v.lower_bound(x) - x;
	return 0;
}
