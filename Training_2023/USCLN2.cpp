#include <iostream>
long long gcd(long long a, long long b){
	if (a < b) std::swap(a, b);
	if (!(a % b)) return b;
	return gcd(b, a % b);
}
int main(){
	long long a,b;
	std::cin >> a >> b;
	std::cout << gcd(a, b);
	return 0;
}
