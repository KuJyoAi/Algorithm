#include<bits/stdc++.h>
using namespace std;
void DFS(int l);
void print();
bool check(int l);
int n;
int res[14];
//res�����ú�����:���ö�ά�������,ʹ��һά����,����ֵ��ʾ���� 
int cnt=0;//�Ѿ��ҵ���ĸ���
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
		//���� 
		res[l]=x;
		if(check(l)){	
			DFS(l+1);
		}
		res[l]=0;
	}
	
	//ȫ��ö������,�˷�֧���� 
	return;
}
bool check(int l){
	int x=res[l];
	int y=l;
	
	//ֻ��Ҫ���l֮ǰ��(����û���) 
	for(int i=0;i<l;i++){
		//ͬ�� 
		if(res[i]==x){
			return false;
		}
		
		//��б��
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
