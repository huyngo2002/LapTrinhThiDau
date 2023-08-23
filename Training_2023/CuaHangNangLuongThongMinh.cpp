#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
int n, m, low, high, ans, a[500005];
bool b[500005];
std::map<int, int> mp;
std::vector<int> vt;
void init(){
	int x = 1; 
	while (x <= 1e9){
		mp.insert({x, 1});
		x *= 2;
	}
	x = 3;
	while (x <= 1e9){
		mp.insert({x, 1});
		x *= 3;
	}
	x = 5;
	while (x <= 1e9){
		mp.insert({x, 1});
		x *= 5;
	}
}
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	init();
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		std::cin >> a[i];
		if (mp.count(a[i])) vt.push_back(a[i]);
	}
	std::sort(vt.begin(), vt.end());
	while (m--){
		ans = 0;
		std::cin >> low >> high;
		for (int i = 0; i < (int)vt.size(); ++i)
			if (vt[i] >= low && vt[i] <= high) ans++;
		std::cout << ans << '\n';
	}
	return 0;
}
