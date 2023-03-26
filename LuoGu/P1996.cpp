#include<bits/stdc++.h>
using namespace std;

queue<int> q;
int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		q.push(i);
	}
	
	int t=1;
	int x=0;
	while(!q.empty()){
		x=q.front();
		q.pop();
		if(t%m!=0){
			q.push(x);
		}else{
			cout<<x+1<<" ";
		}
		
		t++;
	}
}
