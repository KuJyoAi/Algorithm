#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n,m;
int a[100003];

vector<pair<int, int>> ks; // max-min count
unordered_map<int, int> mm; // max-min idx_of_ks
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
			_min = min(_min,a[j]);
			_max = max(_max,a[j]);
			int k = _max - _min;
			
			
			if(!mm.count(k)){
				pair<int, int> tmp;
				tmp.second = 1;
				tmp.first = k;
				mm[k] = ks.size();
				ks.push_back(tmp);
			}else{
				ks[mm[k]].second += 1;
			}
		}
	}  
	
	sort(ks.begin(),ks.end());
	
	
	for(int i=0;i<m;i++){
		int k;
		cin>>k;
		int cnt=0;
		for(int j=ks.size()-1;i>=0;i--){
			if(ks[j].second<=k){
				break;
			}else{
				cnt += ks[j].second;
			}
		}
		cout<<cnt<<endl;
	}
	
}

