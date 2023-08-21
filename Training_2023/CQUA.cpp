#include <iostream>
int main(){
	int n, cnt_1 = 0, cnt_2 = 0;
	std::cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		if (a[i] == 100) ++cnt_1;
		else ++cnt_2;
	}
	if (!cnt_1 && cnt_2 & 1){
	   std::cout << "NO";
	   return 0;
	}
	std::cout << (cnt_1 & 1 == 1 ? "NO" : "YES");
	return 0;
}
