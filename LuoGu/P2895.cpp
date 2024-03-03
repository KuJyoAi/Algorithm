#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
bool cmp(struct met meteor1,struct met meteor2); 
void meteorsDown(int t);
struct block{
	int x,y,l;
};
int m;
int bias[5][2]={{-1,0},{1,0},{0,1},{0,-1},{0,0}};
int hbias[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int bd[302][302];
int vis[302][302];
queue<block> q;
/*
BFS教训:一定要标记走过没
*/
int main(){
	cin>>m;
	int mx,my,t,bx,by;
	for(int i=0;i<m;i++){
		//cin>>mx>>my>>t;
		scanf("%d",&mx);
		scanf("%d",&my);
		scanf("%d",&t);
		for(int i=0;i<5;i++){
			bx=mx+bias[i][0];
			by=my+bias[i][1]; 
			if(bx>=0&&by>=0&&(bd[bx][by]>t||bd[bx][by]==0)){
				bd[bx][by]=t+1;
				//cout<<bx<<" "<<by;
			}
			
		}
	}
	/*for(int y=0;y<10;y++){
		for(int x=0;x<10;x++){
			cout<<bd[x][y];
		}
		cout<<endl;
	}*/
	memset(vis,0,sizeof(vis));
	q.push(block{0,0,0});
	
	int fx,fy,fl;
	block f;
	while(!q.empty()){
		f = q.front();
		fx=f.x;
		fy=f.y;
		fl=f.l;
		q.pop();
		
		for(int p=0;p<4;p++){
			bx=fx+hbias[p][0];
			by=fy+hbias[p][1];
			//cout<<"bx:"<<bx<<"\tby:"<<by<<endl;
			if(bx<0||by<0){
				continue;
			}
			//safe
			if(bd[bx][by]==0){
				cout<<fl+1;
				return 0;
			}
			
			if(bd[bx][by]>fl+2){
				//block tmpt;
				//tmpt.l=fl+1;tmpt.x=bx;tmpt.y=by;
				//q.push(tmpt);
				if(vis[bx][by]==0){
					//first arrive
					q.push(block{bx,by,fl+1});
					vis[bx][by]=1;
				}
				
			}
		}
	}
	cout<<-1;
	return 0;
} 
