#include <iostream>
#include <string>
int n; 
std::string countAndSay(int n){
	std::string ans[31];
	ans[1] = "1";
	for (int i = 2; i <= 30; i++){
		std::string s = ans[i - 1];
		int j = 0, cnt = 1;
		ans[i] = "";
		while (j < (int)s.size()){
			if (s[j] != s[j + 1]){
				ans[i] += std::to_string(cnt);
				ans[i] += s[j];
			    j++;
				cnt = 1;	
			}else{
				cnt++;
				j++;
			}
		}
	}
	return ans[n];
}
int main(){
	std::cin >> n;
	std::cout << countAndSay(n);
	return 0;
}
