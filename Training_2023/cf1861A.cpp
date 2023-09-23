#include <iostream>
#include <string>
int tt;
std::string s;
int main(){
	std::cin >> tt;
	while(tt--){
		std::cin >> s;
		if (s[0] == '1'){
			puts("13");
		}else if (s[0] == '2'){
			puts("23");
		}else if (s[0] == '3'){
			puts("37");
		}else if (s[0] == '4'){
			puts("47");
		}else if (s[0] == '5'){
			puts("53");
		}else if (s[0] == '6'){
			puts("67");
		}else if (s[0] == '7'){
			puts("71");
		}else if (s[0] == '8'){
			puts("83");
		}else{
			puts("97");
		}
	}
	return 0;
}
