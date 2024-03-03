#include <iostream>
#include <unordered_map>
using namespace std;

int n,m;
int a[100003];
unordered_map<int, int> mm; // max-min count
int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<n;i++){
		int _max=a[i];
		int _min=a[i];
		for(int j=i+1;j<n;j++){
			// cout<<"i:"<<i<<"j:"<<j<<endl;
//			ma[i][j] = max(ma[i][j-1],a[j]);
//			mi[i][j] = CSP-2-D.cppmin(mi[i][j-1],a[j]);
			_min = min(_min,a[j]);
			_max = max(_max,a[j]);
//			int k = ma[i][j] - mi[i][j];
			int k = _max - _min;
			mm[k]+=1;
		}
	}  
	// cout<<"ok"<<endl;
	
	for(int i=0;i<m;i++){
		int k;
		cin>>k;
		int cnt=0;
		unordered_map<int,int>::iterator it;
		for(it = mm.begin();it!=mm.end();++it){
			// cout<<it->first<<":"<<it->second<<endl;
			if(it->first<=k){
				continue;
			}else{
				cnt+=it->second;
			}
		}
		cout<<cnt<<endl;
	}
	
}

