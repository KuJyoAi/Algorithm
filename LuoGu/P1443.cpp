#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int bias[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
struct block{
	int x,y;
};
//此题注意x,y的顺序,定义的有点不一样,以后遇到这种情况就反一下看看 
int bd [402][402];
queue<block> Q;
void search();

int main(){
	cin>>n>>m>>y>>x;
	memset(bd,-1,sizeof(bd));
	
	search();
	
	for(int i=1;i<=n;i++,puts("")){
		for(int p=1;p<=m;p++){
			printf("%-5d",bd[p][i]);
		}
	}
	return 0;
}
void search(){
	Q.push(block{x,y});
	bd[x][y]=0;
	
	int bx,by;
	while(!Q.empty()){
		block f = Q.front();	
		int ox,oy;
		ox=f.x;
		oy=f.y;	
		for(int i=0;i<8;i++){
			bx=ox+bias[i][0];
			by=oy+bias[i][1];
			
			if(bx<1||by<1||bx>m||by>n||bd[bx][by]!=-1){
				continue;
			}
			//cout<<"x:"<<f.x<<"\ty:"<<f.y<<endl;
			//cout<<"bx:"<<bx<<"\tby:"<<by<<endl;
			bd[bx][by]=bd[ox][oy]+1;
			Q.push(block{bx,by});
		}
		Q.pop();
	}
}
