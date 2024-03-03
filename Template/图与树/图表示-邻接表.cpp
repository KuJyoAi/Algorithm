#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<bool> vis; // 是否查询过
vector<vector<int> > adj; // 边, 下标i, j, i为出发点, i下面都是以i起点的终点

bool find_edge(int u, int v) {
	for (int i = 0; i < adj[u].size(); ++i) {
		if (adj[u][i] == v) {
			return true;
		}
	}
	return false;
}

void dfs(int u) {
	if (vis[u]) return;
	vis[u] = true;
	for (int i = 0; i < adj[u].size(); ++i) dfs(adj[u][i]);
}

void bfs(int u){
	queue<int> q;
	q.push(u);
	vis[u] = true;
	
	while(!q.empty()){
		int &v = q.front();
		q.pop();
		
		for(auto i:adj[v]){
			if(!vis[i]){
				q.push(i);
				vis[i]=true;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	vis.resize(n + 1, false);
	adj.resize(n + 1);
	
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	
	return 0;
}
