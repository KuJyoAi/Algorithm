#include<iostream>
using namespace std;

int pa[10000];

inline void init(int n){
	for(int i=1;i<=n;i++){
		pa[i]=i;
	}
}

int find(int x){
	// 路径压缩
	return pa[x] == x ? x : pa[x] = find(pa[x]);
}

void unite(int x, int y){
	pa[find(x)] = find(y);
}

// 启发式合并
// int size[10000]; 深度, 注意初始化每个设为1
//void unite(int x, int y){
//	x = find(x), y = find(y);
//	if (x == y) return;
//	if (size[x] < size[y]) swap(x, y);
//	pa[y] = x;
//	size[x] += size[y];
//}
