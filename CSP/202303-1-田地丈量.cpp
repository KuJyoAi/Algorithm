#include<iostream>
using namespace std;

int main(){
	int n, a, b;
	cin>>n>>a>>b;
	unsigned long res = 0;
	for(int i=0;i<n;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		if(x1>=a || y1>=b || x2<=0 || y2 <=0){
			continue;
		}
		
		x1 = x1<0?0:x1;
		y1 = y1<0?0:y1;
		
		x2 = x2>a?a:x2;
		y2 = y2>b?b:y2;
		
		res += (y2-y1)*(x2-x1);
	}
	cout<<res;
}
