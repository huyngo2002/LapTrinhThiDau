#include <iostream>
#include <string>
std::string s1, s2, s;
int tt, cnt_0, cnt_1;
bool check;
char sub(char a, char b){
	if (a == b) return '0';
	return '1';
}
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> tt;
	while (tt--){
		s = "";
		std::cin >> s1 >> s2;
		for (int i = 0; i < (int)s1.size(); ++i){
			s += sub(s1[i], s2[i]);
		}
		cnt_0 = cnt_1 = 0;
		check = true;
		for (int i = 0; i < (int)s.size(); ++i){
			if (!check){
				if (s[i] == '0') {
					if (s1[i] == '0' && cnt_0 > 0) check = true;
					if (s1[i] == '1' && cnt_1 > 0) check = true;
				}
				if (!check){
					if (s[i] == '0'){
						if (s1[i] == '0') cnt_0--;
						else cnt_1--;
					}
				}
			}
			if (s[i] == '0'){
				if (s1[i] == '0') cnt_0++;
				else cnt_1++;
			}else{
				check = false;
			}
		}
		if (check) puts("YES");
		else puts("NO");
	}
	return 0;
}
