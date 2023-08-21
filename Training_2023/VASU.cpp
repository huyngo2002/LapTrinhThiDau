#include <iostream>
#include <vector>
#include <algorithm>
int main(){
	int n, ans = 0;
	std::cin >> n;
	std::vector<int> v(n);
	for (auto& x : v){
		std::cin >> x;
	}
	std::sort(v.begin(), v.end(), [](const int a, const int b){return a > b;});
	while (!v.empty()){
		if (v[0] > 0)
			ans += v[0];
		v.erase(v.begin());
		for (auto& x : v){
			--x;
		}
	}
	std::cout << ans;
	return 0;
}
