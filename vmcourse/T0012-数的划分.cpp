#include<iostream>
using namespace std;

int res = 0;
int n,k;
/*
 * 想象成放球问题: 有n个相同的球和k个盒子
 * dfs搜索放球
 * 为了去重可以保证递归放球的数量是递增的, 即大于start
 */
void dfs(int depth, int remain, int start){
	if(depth==k) {
		if (remain >= start) res++;
		return;
	}
	
	for(int i=start;i<=remain;i++){
		dfs(depth+1, remain-i,i);
	}
}
int main(){
	scanf("%d %d",&n,&k);
	dfs(1,n,1);
	cout<<res;
}
