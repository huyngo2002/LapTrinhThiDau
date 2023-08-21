#include <iostream>
int tt, n, a[100005], ans;
int main(){
	std::cin>>tt;
	while (tt--){
		ans=0;
		std::cin>>n;
		for (int i=1;i<=n;++i) {
			std::cin>>a[i];
			if (a[i]==i) ans++;
		}
		std::cout << (ans&1==1?ans/2+1:ans/2) << '\n';
	}
	return 0;
}
