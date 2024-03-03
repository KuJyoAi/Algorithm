#include<bits/stdc++.h>
using namespace std;
void DFS(int l);
void print();
bool check(int l);
int n;
int res[14];
//res的设置很巧妙:不用二维数组面板,使用一维数组,用数值表示列数 
int cnt=0;//已经找到解的个数
int main(){
	cin>>n;
	DFS(0);
	cout<<cnt;
	return 0;
}

void DFS(int l){
	if(l>=n){
		cnt++;
		if(cnt<=3){
			print();
		}
	}
	
	for(int x=0;x<n;x++){
		//可填 
		res[l]=x;
		if(check(l)){	
			DFS(l+1);
		}
		res[l]=0;
	}
	
	//全部枚举完了,此分支结束 
	return;
}
bool check(int l){
	int x=res[l];
	int y=l;
	
	//只需要检查l之前的(后面没填好) 
	for(int i=0;i<l;i++){
		//同列 
		if(res[i]==x){
			return false;
		}
		
		//共斜线
		if(abs(res[i]-x)==abs(i-y)){
			return false; 
		}
	}
	
	return true;
}

void print(){
	for(int y=0;y<n;y++){
		cout<<res[y]+1<<" ";
	}
	cout<<endl;
}
