#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<vector<int> > v;
	int n,q;
	cin>>n>>q;
	
	v.resize(n+1);
	
	int c,i,j,k;
	while(q--){
		cin>>c;
		if(c==1){
			cin>>i>>j>>k;
			
			if((int)v[i-1].size()<j){
				v[i-1].resize(j);
			}
			v[i-1][j-1]=k;
		}else{
			cin>>i>>j;
			
			cout<<v[i-1][j-1]<<endl;
		}
	}
	
	
	return 0;
}
