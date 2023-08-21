#include <iostream>
int tt;
long long n;
int main(){
	std::cin>>tt;
	while(tt--){
		std::cin>>n;
		int i=1; 
		while (n%i==0) ++i;
		std::cout<<i-1<<'\n';
	}
	return 0;
}
