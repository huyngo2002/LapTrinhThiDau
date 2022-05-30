// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q8
#include <bits/stdc++.h>
using namespace std;
int longestUniqueSubsttr(string str) {
	int n = str.size();
	int res = 0;
	for (int i = 0; i < n; i++) {
		bool visited[256] = {};
		for (int j = i; j < n; j++) {
			if (visited[str[j]] == true)
				break;
			else {
				res = max(res, j - i + 1);
				visited[str[j]] = true;
			}
		}
		visited[str[i]] = false;
	}
	return res;
}
int main() {
	string s;
	getline(cin, s);
	int length = longestUniqueSubsttr(s);
	cout << length;
}
