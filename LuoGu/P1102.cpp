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
	//A=B+C;ȡһ��B,�ж�C�Ƿ����
	/*
	ԭ��:
	��map��¼�����ֵĴ���(����map����,û����Ĭ��0)
	����һ�������¼����ֵ
	���ǽ������ÿһ��ֵ+c,ȥmap��ȡ,���ɵõ�cnt; 
	*/
	long long cnt=0;//�ӵ�:cnt̫����,��long long 
	for(int i=0;i<n;i++){
		cnt+=m[a[i]+c];
	}
	cout<<cnt;
	return 0;
}
