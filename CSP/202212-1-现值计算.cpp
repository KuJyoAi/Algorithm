#include<iostream>

using namespace std;

int n;
double is;

int main(){
	double r=1;
	double res = 0;
	scanf("%d %lf %lf",&n, &is, &res);
	
	for(int i=0;i<n;i++){
		double num;
		scanf("%lf",&num);
		r = r * (1+is);
		res += num / r;
		
	}	
	
	cout<<res;
}
