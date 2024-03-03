#include<iostream>
#include<vector>
#define MAXN 100000
using namespace std;

vector<bool> isnp;
vector<int> primes; //质数表

void Eule(int n){
	for(int i=2;i<=n;i++){
		if(!isnp[i]){
			primes.push_back(i);
		}
		
		for(auto p:primes){
			if(p*i>n){
				break;
			}
			isnp[p*i]=1;
			if(i%p==0){
				break;
			}
		}
	}
}

int main(){
	int n=2038074743;
	isnp.resize(n+1);
	Eule(n+1);
	cout<<primes.size()<<endl;
	cout<<primes[primes.size()-1];
}
