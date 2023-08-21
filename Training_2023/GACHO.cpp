#include <iostream>
int main(){
	int n, m, c = 0, g = 0;
	std::cin >> n >> m;
	c = (m - 2 * n) / 2;
	g = (n - c);
	if (m & 1 == 1) {
		std::cout << "-1";
		return 0;
	}
	if (c >= 0 && g >= 0) std::cout << g << ' ' << c;
	else std::cout << "-1";
	return 0;
}
