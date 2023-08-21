#include <iostream>
bool isPrime(int n){
	if (n<2) return false;
	for (int i=2;i*i<=n;++i)
		if (n%i==0) return false;
	return true;
}
int main(){
	int x,sum=0,cnt=0;
	char check;
	while (std::cin>>x){
		if (isPrime(x)) {sum+=x;++cnt;}
		check=std::cin.get();
		if (check=='\n') break;
	}
	if (!sum) printf("-");
	else printf("%.2f",sum*1.0/cnt);
	return 0;
}
