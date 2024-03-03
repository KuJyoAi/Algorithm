#include<iostream>
using namespace std;
int fa[10003];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y){
	fa[find(x)] = find(y);
}

#define long long double lld
// 0 --> not linked, 1 --> linked
inline bool isLink(int x1, int y1, int z1, int x2, int y2, int z2, int r){
	int dz = abs(z1 - z2);
	if (dz > r){
		return false;
	}
	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);
	if (dx * dx + dy * dy + dz * dz > r * r){
		return false;
	}
	
	return true;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int n,h,r;
		scanf("%d %d %d",&n,&h,&r);
		
		
	}
}
