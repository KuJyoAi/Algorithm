#include<bits/stdc++.h>
//深度优先搜索典型题 
using namespace std;
int a[25],s[4];
double sum,half;
void search(int layer,int i);
double tmptime=0,maxtime=0,res=0;
int main(){
	for(int i=0;i<4;i++){
		cin>>s[i];
	}
	
	for(int i=0;i<4;i++){
		sum=0,maxtime=0,tmptime=0;
		memset(a,0,sizeof(a));
		for(int p=0;p<s[i];p++){
			cin>>a[p];
			sum+=a[p];
		}
		half=sum/2;
		search(0,i);
		res+=max(maxtime, sum-maxtime);
		//cout<<endl<<"||"<<res<<"||";
	}
	cout<<res;
	return 0;
} 


void search(int layer,int i){
	if(layer>=s[i]){
		maxtime=max(maxtime,tmptime);
		return;
	}
	
	if(tmptime+a[layer]<=half){
		tmptime+=a[layer];
		search(layer+1,i);
		tmptime-=a[layer];
	}
	
	search(layer+1,i);
	
	
	
}
