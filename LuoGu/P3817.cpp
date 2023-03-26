#include<iostream>
using namespace std;
int a[100003];
long long cnt=0;

int main(){
	int n,x;
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	/*
	if(a[0]>x){
		cnt=a[0]-(x-a[1]);
		a[0]=x-a[1];
	}
	*/
	for(int i=0;i<n-1;i++){
		if(a[i]+a[i+1]<=x){
			continue;
		}

		int eat=a[i]+a[i+1]-x;
		//cout<<"i:"<<i<<" eat:"<<eat<<endl;
		a[i+1]-=eat;
		cnt+=eat;
	}

	/*for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}*/
	cout<<cnt;
}
