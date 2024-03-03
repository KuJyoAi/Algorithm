#include<bits/stdc++.h>
using namespace std;
//记得检查特殊情况,这里的-1 
int N,A,B;//楼层数,start,end 
int cnt=0;
int K[202];
queue<struct layer> Q;
struct layer{
	int p,k;
};
int main(){
	cin>>N>>A>>B;
	for(int i=1;i<=N;i++){
		cin>>K[i];
	}
	Q.push(layer{A,K[A]});
	
	int p1=1,p2=0,t=0;//本层和下一层深度的查找次数,已查找次数 
	struct layer l;
	while(!Q.empty()){
		while(t<p1){
			l = Q.front();
			Q.pop();
			
			if(l.p==B){
				cout<<cnt;
				return 0;
			}
			
			//合法且未去过 
			if(l.p-l.k>0&&K[l.p-l.k]!=-1){
				Q.push(layer{l.p-l.k,K[l.p-l.k]});
				K[l.p]=-1;
				p2++;
			}
			
			if(l.p+l.k<=N&&K[l.p+l.k]!=-1){
				Q.push(layer{l.p+l.k,K[l.p+l.k]});
				K[l.p]=-1;
				p2++;
			}
			
			t++;
		}
		p1=p2;
		p2=0;
		t=0;
		cnt++;	
	}
	cout<<-1;
	return 0;
}
