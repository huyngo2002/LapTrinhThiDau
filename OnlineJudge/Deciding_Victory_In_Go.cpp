// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q11
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0,  0, -1, 1, 1, -1};
int T, Black, White, B, W, cnt;
char ch;
vector<string> ve;
vector<vi>vis;
bool vaild(int i, int j) {
	if (i >= 0 && j >= 0 && i < 9 && j < 9 && !vis[i][j])
		return true;
	return false;
}
void dfs(int i, int j) {
	cnt++;
	vis[i][j] = 1;
	for (int x = 0; x < 4; x++) {
		int to_x = i + dx[x];
		int to_y = j + dy[x];
		if (vaild(to_x, to_y)) {
			if (ve[to_x][to_y] == '.')
				dfs(to_x, to_y);
			else {
				B &= (ve[to_x][to_y] != 'X');
				W &= (ve[to_x][to_y] != 'O');
			}
		}
	}
}
void solve() {
	cin >> T;
	while(T--) {
		ve = vector<string>(9);
		vis = vector<vi>(9, vi(9, 0));
		Black = White = 0;
		for (auto& it : ve)
			cin >> it;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				White += (ve[i][j] == 'O');
				Black += (ve[i][j] == 'X');
				if (ve[i][j] == '.' && !vis[i][j]) {
					cnt = 0;
					B = W = 1;
					dfs(i, j);
					if (B && !W)
						White += cnt;
					else if (W && !B)
						Black += cnt;
				}
			}
		}
		cout << "Black " << Black << " White " << White << "\n";
	}
}
int main() {
	solve();
}
