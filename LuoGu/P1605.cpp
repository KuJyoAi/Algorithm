#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int sx,sy,ex,ey;
int bd[7][7];

int cnt=0;
int walk[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int x, int y){
	if(x==ex&&y==ey){
		cnt++;
		return;
	}else {
		int bx,by;
		for(int i=0;i<4;i++){
			bx=x+walk[i][0];
			by=y+walk[i][1];
			
			if(bx<=0||by<=0||bx>m||by>n){
				continue;
			}else if(bd[bx][by]==1){
				continue;
			}else{
				bd[bx][by]=1;
				dfs(bx,by);
				bd[bx][by]=0;
			}
		}
	}
}
int main(){
	cin>>n>>m>>t>>sx>>sy>>ex>>ey;
	
	int tx,ty;
	for(int i=0;i<t;i++){
		cin>>tx>>ty;
		bd[tx][ty]++;//走过的和障碍都标为1; 
	}
	bd[sx][sy]++;
	dfs(sx,sy);
	cout<<cnt;
} 
