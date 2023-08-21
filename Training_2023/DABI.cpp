#include <iostream>
#include <string>
int main(){
	std::string n;
	long long _n = 0;
	std::cin >> n;
	int sum = 0;
	for (char c : n){
		sum += (c - '0');
		_n = (_n * 10 + (c - '0'));
	}
	std::cout << (_n % sum == 0 ? '1' : '0');	
	return 0;
}
