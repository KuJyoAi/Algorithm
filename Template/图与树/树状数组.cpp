#include<iostream>
using namespace std;

int n = 10;
int a[10000];
int c[10000];

#define lowbit(x) (x)&(-x)

//inline int lowbit(int x) {
//	// x 的二进制中，最低位的 1 以及后面所有 0 组成的数。
//	// lowbit(0b01011000) == 0b00001000
//	//          ~~~~^~~~
//	// lowbit(0b01110010) == 0b00000010
//	//          ~~~~~~^~
//	return x & -x;
//}

int getsum(int x) {  // a[1]..a[x]的和
	int ans = 0;
	while (x > 0) {
		ans = ans + c[x];
		x = x - lowbit(x);
	}
	return ans;
}

void add(int x, int k) {
	while (x <= n) {  // 不能越界
		c[x] = c[x] + k;
		x = x + lowbit(x);
	}
}

void init() {
	for (int i = 1; i <= n; ++i) {
		c[i] += a[i];
		int j = i + lowbit(i);
		if (j <= n) c[j] += c[i];
	}
}

int main(){
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	
	init();
	
	
	for(int i=1;i<=n;i++){
		cout<<getsum(i)<<" ";
	}
	
	cout<<endl;
	add(1,2);
	add(2,2);
	for(int i=1;i<=n;i++){
		cout<<getsum(i)<<" ";
	}
}
