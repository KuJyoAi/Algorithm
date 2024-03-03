#include<iostream>
#include<numeric>
using namespace std;
int commonFactors(int a, int b) {
	int g = gcd(a,b);
	int cnt = 0;
	for(int i=1;i*i<=g;i++){
		if(g%i==0){
			cnt++;
			// 如果i*i!=g, 总是存在另外一边的因子
			cnt+=(i*i<g);
		}
	}
	return cnt;
}

int main(){
	cout<<commonFactors(12,6);
}
