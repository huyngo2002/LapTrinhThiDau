#include <iostream>
int t, n;
long long S;
int main () {
	std::cin >> t;
	while (t--){
		std::cin >> n >> S;
		if (1LL * (n + 1) * n / 2 - S > n || 1LL * (n + 1) * n / 2 - S < 0) std::cout << "0\n"; 
	   	else std::cout << 1LL * (n + 1) * n / 2 - S << '\n';
	}
	return 0;
}
