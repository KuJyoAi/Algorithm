#include<bits/stdc++.h>
using namespace std;
int a[100];
int min(int a,int b){
	return a<b ? a:b;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int b=a[0];
	for(int i=1;i<n;i++){
//		b=min(a[i],b);
		b=min(a[i],a[i-1]);
	} 
	cout<<b;
	return 0;
}
