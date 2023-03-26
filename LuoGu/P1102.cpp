#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int a[200005]={0};
int main(){
	int n,c;
	cin>>n>>c;
	int num;
	for(int i=0;i<n;i++){
		cin>>num;
		m[num]++;
		a[i]=num;
	}
	//A=B+C;取一个B,判断C是否存在
	/*
	原理:
	用map记录数出现的次数(由于map特性,没出现默认0)
	再用一个数组记录数的值
	于是将数组的每一个值+c,去map中取,即可得到cnt; 
	*/
	long long cnt=0;//坑点:cnt太大了,用long long 
	for(int i=0;i<n;i++){
		cnt+=m[a[i]+c];
	}
	cout<<cnt;
	return 0;
}
