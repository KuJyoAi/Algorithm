#include<iostream>

using namespace std;

int main(){
	char chs[13];
	cin>>chs;
	
	int i=0;
	unsigned long long res=0;
	while(chs[i] != '\0'){
		res = res * 26 + chs[i] - 'A' + 1;
		i++;
	}
	cout<<res;
}
