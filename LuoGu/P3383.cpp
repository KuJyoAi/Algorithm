#include<bits/stdc++.h>
using namespace std;
bitset<1000000001> isp;
vector<int>primes;//质数表,假设都是素数,然后筛掉 
int query[1000001];
int main(){
	//ios::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<q;i++){
		cin>>query[i];
	}
	
	for(int i=2;i<=n;i++){
		if(!isp[i]){
			primes.push_back(i);
		}
		
		//遍历素数表 
		for(int p=0;p<primes.size();p++){
			if(primes[p]*i>n){
				break;
			}
				
			//筛除 
			isp[primes[p]*i]=true;
			
			//这里有数论定理:如果对x,x|p,则不需要继续筛了(后面会筛到) 
			if(i%primes[p]==0){
				break;
			}			
		}
	}
		
	for(int i=0;i<q;i++){
		cout<<primes[query[i]-1]<<endl;
	}
	
	return 0;
} 
