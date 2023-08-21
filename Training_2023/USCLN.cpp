#include <iostream>
int a,b;
int _gcd(int a,int b){
	if (!a||!b) return (a>=b)*a+(b>a)*b;
	if (!(a%b)) return b;
	return _gcd(b,a%b);
}
int main(){
	std::cin>>a>>b;
	std::cout << _gcd(a,b);
	return 0;
}
