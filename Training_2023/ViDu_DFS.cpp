#include <iostream>
#include <vector>
int V, E, start;
std::vector<int> adj[100005];
bool visited[100005];
void dfs(int u){
	visited[u] = true;
	for (int i = 0; i < (int)adj[u].size(); ++i){
		int v = adj[u][i];
		if (!visited[v]) dfs(v);
	}
}
int main(){
	std::cin >> V >> E >> start;
	for (int i = 1; i <= E; ++i){
		int u, v;
		std::cin >> u >> v;
		adj[u].push_back(v);
	}
	dfs(start);
	for (int i = 1; i <= V; ++i){
		if (visited[i]) std::cout << i << ' ';
	}
}
