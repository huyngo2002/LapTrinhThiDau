#include <iostream>
#include <cstring>
int T, N, M;
char a[22][22];
bool vis[22][22][12];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void dfs(int x, int y, int p){
	vis[x][y][p] = true;
	for (int i = 0; i < 4; ++i){
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (newx >= 1 && newx <= N && newy >= 1 && newy <= M && a[newx][newy] != '#'){
			int newp = p;
			if ('1' <= a[newx][newy] && a[newx][newy] <= '9') newp += (a[newx][newy] - '0');
			if (a[newx][newy] == 'S') newp = 0;
			if (newp >= 10) continue;
			if (!vis[newx][newy][newp]) dfs(newx, newy, newp);
		}
	}	
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> T;
	while (T--){
		std::memset(vis, 0, sizeof vis);
		std::cin >> N >> M;
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j <= M; ++j){
				std::cin >> a[i][j];
			}
		}
		dfs(1, 1, 0);
		bool check = false;
		for (int i = 0; i <= 9; ++i){
			if (vis[N][M][i]) {
				check = true;
				break;
			}
		}
		if (!check) puts("impossible");
		else puts("possible");
	}
	return 0;
}
