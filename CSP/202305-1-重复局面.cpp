#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
char p[64];
unordered_map<string, int> m;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<64;j++){
			cin>>p[j];
		}
		if(m.count(p)){
			m[p]++;
		}else{
			m[p]=1;
		}
		cout<<m[p]<<endl;
	}
	return 0;
}
