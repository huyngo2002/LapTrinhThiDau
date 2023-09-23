#include <iostream>
#include <string>
#include <vector>
int tt, num;
std::string s;
char c;
bool flag;
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> tt;
	while (tt--){
		std::cin >> s;
		std::vector<int> v;
		flag = true;
		if (s[0] == '-' || s[0] == '0' || s[0] == '1' || ((int)s.size() >= 2 && s[0] == '+' && s[1] == '0')){
			puts("NO");
			continue;
		}
		for (int i = 0; i < (int)s.size(); ++i){
			if (s[i] == '0') {
				num = i;
				c = '0';
				break;
			}
			if (s[i] == '1') {
				num = i;
				c = '1';
				break;
			}
		}
		bool sav = true;
		if (c == '0'){
			for (int i = 1; i < num; ++i){
				v.push_back(i);
			}
			v.push_back(num - 2);
			sav = false;
		}else{
			for (int i = 1; i <= num; ++i){
				v.push_back(i);
			}
		}
		for (int i = num + 1; i < (int)s.size(); ++i){
			if (s[i] == '-'){
				if (i == num + 1){
					v.pop_back();
					sav = true;
				}else{
					v.pop_back();
				}
			}
			if (s[i] == '+'){
				v.push_back(v[(int)v.size() - 1] + 2);
			}
			if (s[i] == '0'){
				if (s[i - 1] == '+'){
					if ((int)v.size() > 0)
						v.pop_back();
					v.push_back(v[(int)v.size() - 1] - 1);
					flag = true;
					if ((int)v.size() == 1) flag = false;
					continue;
				}
				if (sav) {
					flag = false;
					break;
				}	
			}
			if (s[i] == '1'){
				if (!sav){
					flag = false;
					break;
				}
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
