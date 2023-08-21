#include <iostream>
int n, m, h[1005][1005], count = 0;
bool tick[1005][1005];
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			std::cin >> h[i][j];
	for (int i = 1; i <= n; ++i){
		if (!tick[i][1] && h[i][1] > 0) {
			++count;
			tick[i][1] = true;
		}
		int cur = h[i][1];
		for (int j = 2; j <= m; ++j){
			if (h[i][j] > cur && !tick[i][j] && h[i][j] > 0){
				++count;
				tick[i][j] = true;
			}
			if (h[i][j] > cur) cur = h[i][j];
		}	
	}
	for (int i = 1; i <= n; ++i){
		if (!tick[i][m] && h[i][m] > 0) {
			++count; 
			tick[i][m] = true;
		}
		int cur = h[i][m];
		for (int j = m - 1; j >= 1; --j){
			if (h[i][j] > cur && !tick[i][j] && h[i][j] > 0){
				++count;
				tick[i][j] = true;
			}
			if (h[i][j] > cur) cur = h[i][j];
		}	
	}
	for (int j = 1; j <= m; ++j){
		if (!tick[1][j] && h[1][j] > 0){ 
			++count;	
			tick[1][j] = true;
		}
		int cur = h[1][j];
		for (int i = 2; i <= n; ++i){
			if (h[i][j] > cur && !tick[i][j] && h[i][j] > 0){
				++count;
				tick[i][j] = true;
			}
			if (h[i][j] > cur) cur = h[i][j];
		}
	}
	for (int j = 1; j <= m; ++j){
		if (!tick[n][j] && h[n][j] > 0) {
			++count;
			tick[n][j] = true;
		}
		int cur = h[n][j];
		for (int i = n - 1; i >= 1; --i){
			if (h[i][j] > cur && !tick[i][j] && h[i][j] > 0){
				++count;
				tick[i][j] = true;
			}
			if (h[i][j] > cur) cur = h[i][j];
		}
	}
	std::cout << count;
	return 0; 	
}

