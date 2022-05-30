// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q40
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int a[1005], b[1005];
int dp1[10], dp2[10], dp3[10], ans[1005], ans1[1005];
int min(int a, int b) {
	return a < b ? a : b;
}
int main () {
	int i, j, m, n, leap, temp = 1;
	while(scanf("%d", &n) != EOF) {
		if (n == 0) break;
		memset(dp1, 0, sizeof(dp1));
		for (i = 1; i <= n; i++) {
			cin >> a[i];
			dp1[a[i]]++;
		}
		leap = 1;
		j = 1;
		while(leap) {
			leap = 0;
			ans[j] = 0;
			ans1[j] = 0;
			memset(dp2, 0, sizeof(dp2));
			memset(dp3, 0, sizeof(dp3));
			for (i = 1; i <= n; i++) {
				cin >> b[i];
				if (b[i] == a[i]) {
					ans[j]++;
					dp3[b[i]]++;
				} else
					dp2[b[i]]++;
				if (b[i])
					leap = 1;
			}
			if (leap) {
				for (i = 1; i <= 9; i++) {
					ans1[j] = ans1[j] + min(dp1[i] - dp3[i], dp2[i]);
				}
				j++;
			}
		}
		cout << "Game " << temp << ":" << endl;
		for (i = 1; i < j; i++)
			cout << "(" << ans[i] << "," << ans1[i] << ")" << endl;
		temp++;
	}
	return 0;
}
