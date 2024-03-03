#include<iostream>
using namespace std;

#define MAXN 0x3f3f3f
#define N 20007

int ans=MAXN;
int mins[N],minv[N],n,m;
//  当前层数 上一层半径  上一层高度 面积  体积
void dfs(int now,int r,int h,int s,int v) {
	int MAXN_high=h;
	if(now==0) {
		if(v==n) {
			ans=min(ans,s);
		}
		return ;
	}
	
	if(s+mins[now-1]>=ans) return ;
	if(v+minv[now-1]>n) return;
	if(2*(n-v)/r+s>=ans)  return;
	
	
	// 从上一层高度开始遍历
	for(int i=r-1; i>=now; --i) {
		if(now==m) s=i*i; // +底面积
		
		// 最大高度, 有两个约束: 1. 下面的比上面的高 2.不能超过底面积
		MAXN_high=min(h-1 ,(n-minv[now-1]-v)/i/i);
		for(int j=MAXN_high; j>=now; --j) {
			dfs(now-1,i,j,s+2*i*j,v+i*i*j);
		}
	}
}
int main() {
	cin>>n>>m;
	/*初始化每层成最小的表面积和体积*/
	for(int i=1; i<=m; ++i) {
		mins[i]=mins[i-1]+2*i*i;//计算面积
		minv[i]=minv[i]+i*i*i;//计算体积
	}
	dfs(m,n,n,0,0);
	if(ans==MAXN) 
		cout<<0;
	else 
		cout<<ans;
	return 0;
}
