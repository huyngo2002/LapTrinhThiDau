// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q30
#include<bits/stdc++.h>
using namespace std;
string countAndSay(int n) {
	if(n==1) {
		return "1";
	}
	string prev=countAndSay(n-1);
	string ans;
	int len=prev.length();
	for(int i=0; i<len;) {
		int j=i;
		int count=0;
		while(prev[j]==prev[i]&&j<len) {
			j++;
			count++;
		}
		char c='0'+count;
		ans+=c;
		ans+=prev[i];
		i=j;
	}
	return ans;
}
int main() {
	int n;
	while(cin >> n)
		cout << countAndSay(n) << endl;
	return 0;
}
