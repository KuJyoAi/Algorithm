#include<bits/stdc++.h>
using namespace std;
bool b[10000]={true};
int main(){
	int n;
	cin>>n;
	memset(b,1,sizeof(b));
	for(int i=2;i*i<=n;i++){
		if(b[i]){
			for(int j=i*i;j<=n;j+=i){
				b[j]=false;
			}
		}
	}
	
	
	for(int i=2;i<=n;i++){
		if(b[i]){
			cout<<i<<" ";
		}
	}
	return 0;
}
