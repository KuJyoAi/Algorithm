#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v;
	int n,m;
	cin>>n>>m;
	int tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		v.push_back(tmp);
	}
	for(int i=0;i<m;i++){
		cin>>tmp;
		cout<<v[tmp-1]<<endl;
	}
	return 0;
}
