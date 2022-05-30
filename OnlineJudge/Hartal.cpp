// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q20
#include<stdio.h>
#include<string.h>
#define MAXN 3650 + 10
int data[MAXN];
int main() {

	int i, j, cnt, p[110], T, n, m;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(i=1; i<=n; ++i) data[i] = 0;
		scanf("%d", &m);
		for(i=0; i<m; ++i) {
			scanf("%d", &p[i]);
			for(j=1; j<=n; ++j)
				if(j/p[i] != 0 && j%p[i] == 0) data[j] = 1;
		}
		for(cnt=0,i=1; i<=n; i++) {
			if((i+1)%7 == 0 || i%7 == 0) continue;
			cnt += data[i];
		}
		printf("%d\n", cnt);

	}
	return 0;
}
