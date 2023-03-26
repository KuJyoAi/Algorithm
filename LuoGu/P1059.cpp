#include<bits/stdc++.h>
using namespace std;

int a[1000]={0};
int main(){
	int n;
	cin>>n;
	int tmp=0;
	int cnt=0;
	
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		if(a[tmp]==0){
			cnt++;
			a[tmp]++;
		}
	}
	cout<<cnt<<endl;
	for(int i=0;i<1000;i++){
		if(a[i]!=0){
			cout<<i<<" ";
		}
	}
}
