#include<iostream>
using namespace std;
#define MAXN 1000000
bool isnp[MAXN]; //标记是否为 非素数

// 埃氏筛
void Eratosthens(int n){
	for(int i=2;i*i<=n;i++){
		if(!isnp[i]){
			for(int j=i*i;j<=n;j+=i){
				isnp[j] = 1;
			}
		}
	}
}

int main(){
	Eratosthens(10000);
	for(int i=2;i<=10000;i++){
		if(!isnp[i]){
			cout<<i<<" ";
		}
	}
}
