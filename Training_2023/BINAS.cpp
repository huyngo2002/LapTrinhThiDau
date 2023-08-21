#include <iostream>
int a[21], n;
void show(){
	for (int i = 0; i < n; ++i) std::cout << a[i];
	std::cout << '\n';
}
void back(int i){
	if (i == n) {
		show();
		return;
	}
	a[i] = 0;
	back(i + 1);
	a[i] = 1;
	back(i + 1);
}
int main(){
	std::cin >> n;
	back(0);
	return 0;
}
