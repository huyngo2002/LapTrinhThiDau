#include <iostream>
int main(){
	int a, n, ans;
	std::cin >> a >> n;
	ans = a % 10;
	for (int i = 1; i < n; ++i){
		ans = ((a % 10) * ans) % 10;
	}
	std::cout << ans;
	return 0;	
}
