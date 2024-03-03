#include<iostream>
using namespace std;

// ax + by = gcd(a,b), d=gcd(a,b)
long long exgcd(long long a, long long b, long long &x, long long &y){
	if (b == 0){
		x = 1;
		y = 0;
		return a;
	}
	long long d = exgcd(b, a % b, x, y);
	long long t = x;
	x = y;
	y = t - a / b * y;
	return d;
}

int main(){
	long long a, m;
	cin>>a>>m;
	// 求a模m的逆元
	long long x, y;
	long long d = exgcd(a, m, x, y);
	if (d == 1){
		x = (x % m + m) % m;
		cout<<x;
	}else{
		cout<<"No Solution";
	}
	return 0;
}
