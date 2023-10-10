// Link: https://www.beecrowd.com.br/judge/en/problems/view/1610?origem=1
// Dạng: Đồ thi DAG (Đồ thị không có chu trình)
#include <iostream>
#include <vector>
std::vector<int> adj[10005];
int visited[10005];
int n, m, tt;
bool ans = false;
void dag(int u)
{
    if (ans == true)
    {
        return;
    }
    visited[u] = 1;
    for (int i = 0, v; i < (int)adj[u].size(); ++i)
    {
        v = adj[u][i];
        if (visited[v] == 1)
        {
            ans = true;
            return;
        }
        if (visited[v] == 0)
        {
            dag(v);
        }
    }
    visited[u] = 2;
}
int main ()
{
    std::cin >> tt;
    while (tt--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            adj[i].clear();
            visited[i] = 0;
        }
        for (int i = 1, a, b; i <= m; ++i)
        {
            std::cin >> a >> b;
            adj[a].push_back(b);
        }
        ans = false;
        for (int i = 1; i <= n; ++i)
        {
            if (visited[i] == 0)
            {
                dag(i);
            }
        }
        std::cout << (ans == true ? "SIM" : "NAO") << '\n';
    }
    return 0;
}
