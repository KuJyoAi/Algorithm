#include<iostream>
using namespace std;
int n,m,k;
int bd[105][105];
void setM(int x,int y);
void setK(int x,int y);
int main(){
	cin>>n>>m>>k;
	int x,y;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		setM(x-1,y-1);
	}
	for(int i=0;i<k;i++){
		cin>>x>>y;
		setK(x-1,y-1);
	}
	
	int cnt=0;
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			if(bd[a][b]==0){
				cnt++;
				
				//cout<<"p:"<<a<<","<<b<<endl;
			}
			//cout<<bd[a][b]<<" ";
		}
		//cout<<endl;
	}
	cout<<cnt;
	
} 
void setK(int x, int y){
	for(int a=x-2;a<x+3 && a>=0;a++){
		for(int b=y-2;b<y+3 && b>=0;b++){
			bd[a][b]++;
			//cout<<"p:"<<a<<","<<b<<endl;
		}
	}
}
void setM(int x, int y){
	int biax[]={-2,-1,0,1,2,0,0,0,0,-1,-1,1,1};
	int biay[]={0,0,0,0,0,-2,-1,1,2,-1,1,-1,1};
	int px,py;
	for(int a=0;a<13;a++){
			px=x+biax[a];
			py=y+biay[a];
			//cout<<"p:"<<px<<","<<py<<endl;
			if(px >=0&&py>=0){
				bd[px][py]++;
				
			}
			
	}
}
