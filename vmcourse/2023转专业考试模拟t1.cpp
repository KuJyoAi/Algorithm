#include<iostream>

using namespace std;

int main(){
	unsigned long long res = 0;
	unsigned long long a_cnt = 0;
	unsigned long long idx = 0;
	do{
		char ch = getchar();
		if(ch == EOF || ch == '\n'){
			break;
		}
		
		if(ch=='A'){
			res += idx - a_cnt;
			a_cnt++;
		}
		idx++;
	}while(1);
	cout<<res;

}
