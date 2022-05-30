// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q19
#include <bits/stdc++.h>
using namespace std;
int main () {
	int a, b;
	while(true) {
		cin >> a >> b;
		if (a == 0 and b == 0)
			break;
		else {
			int cnt = 0;
			for (int i = a; i <= b; i++)
				if (sqrt(i) == (float)sqrt(i))
					cnt++;
			cout << cnt << endl;
		}
	}
	return 0;
}
