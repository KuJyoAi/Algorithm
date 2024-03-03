#include<iostream>
using namespace std;
int fa[10003];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y){
	fa[find(x)] = find(y);
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<=n;i++){
		fa[i] = i;
	}
	
	int z,x,y;
	int res=0;
	for(int i=0;i<m;i++){
		scanf("%d %d %d", &z, &x, &y);
		if (z==0){
			// union
			unite(x,y);
		}else{
			// find
			int ans = (find(x) == find(y));
//			printf("--%d--\n",ans);
			res = res<<1 | ans;
			res %= 998244353;
		}
	}
	printf("%d",res);
}
