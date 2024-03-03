#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<bool> vis; // 是否查过
vector<vector<bool> > adj; // 边, 改成int可以变成有权图 

bool find_edge(int u, int v) { return adj[u][v]; }

void dfs(int u) {
	if (vis[u]) return;
	vis[u] = true;
	for (int v = 1; v <= n; ++v) {
		if (adj[u][v]) {
			dfs(v);
		}
	}
}

int main() {
	cin >> n >> m;
	
	vis.resize(n + 1, false);
	adj.resize(n + 1, vector<bool>(n + 1, false));
	
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = true;
	}
	
	return 0;
}
