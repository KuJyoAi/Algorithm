#include<bits/stdc++.h>
using namespace std;
bitset<1000000001> isp;
vector<int>primes;//������,���趼������,Ȼ��ɸ�� 
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
		
		//���������� 
		for(int p=0;p<primes.size();p++){
			if(primes[p]*i>n){
				break;
			}
				
			//ɸ�� 
			isp[primes[p]*i]=true;
			
			//���������۶���:�����x,x|p,����Ҫ����ɸ��(�����ɸ��) 
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
