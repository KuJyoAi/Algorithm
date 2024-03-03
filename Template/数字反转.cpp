#include<iostream>

using namespace std;

int reverse(int n){
	int res = 0;
	while(n){
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}

int main(){
	for(int i=1;i<=100;i++){
		cout<<i<<"\t"<<reverse(i)<<endl;
	}
}
