#include <iostream>
int main(){
	int chai, vo = 0, ans = 0;
	std::cin >> chai; 
	while (vo >= 10 || chai > 0){
		if (chai < 10) {
			ans += chai;
			chai = 0;
			vo += chai;
		}
		if (chai >= 10){
			ans += (chai - chai % 10);
			vo += (chai - chai % 10);
			chai = (chai % 10);
		}
		if (vo >= 10){
			chai += (vo / 10 * 3);
			vo -= (vo / 10) * 10;
		}
	}
	std::cout << ans;
	return 0;
}
