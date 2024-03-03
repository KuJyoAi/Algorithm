#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
#define maxn 10000

struct edge {
	int v, w;
};
struct node {
	int dis, u;
};
bool operator<(const node &n1, const node &n2){
	return n1.dis < n2.dis;
}
vector<edge> e[maxn];
int dis[maxn], vis[maxn];
priority_queue<node, vector<node>> q;
// int pre[v] = u
// n为节点数, s为起始点
void dijkstra(int n, int s) {
	memset(dis, 63, sizeof(dis)); // 初始化所有点为无限大
	dis[s] = 0; // 起始点dis=0
	q.push({0, s});
	while (!q.empty()) {
		int u = q.top().u;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto ed : e[u]) {
			int v = ed.v, w = ed.w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
}

int main(){
	
}
