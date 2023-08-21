#include <iostream>
#include <string>
#include <vector>
bool check(int n){
	std::string s = std::to_string(n);
	for (int i = 0; i < (int)s.size(); ++i){
		if (s[i] != s[(int)s.size() - 1 - i]) return false;
	}
	return true;
}
int main(){
	int n;
	std::cin >> n;
	int *a = new int[n];
	std::vector<int> res;
	for (int i = 0; i < n; ++i){
		std::cin >> a[i];
		if (check(a[i])) res.push_back(a[i]); 
	}
	for (const auto& x : res) std::cout << x << ' ';
	return 0;
}
