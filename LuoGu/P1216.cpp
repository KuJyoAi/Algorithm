#include<iostream>
#define MaxR 1003
using namespace std;

int r;
int num[MaxR][MaxR];
int main(){
	cin>>r;
	cin>>num[1][1];
	if(r==1){
		cout<<num[1][1];
		return 0;
	}

	for(int i=2;i<=r;i++){
		int a;
		for(int p=1;p<=i;p++){
			cin>>a;
			num[i][p]=max(num[i-1][p-1],num[i-1][p])+a;
		}
	}

	int max=0;
	for(int i=1;i<=r;i++){
		if(max<num[r][i]){
			max=num[r][i];
		}
	}
	cout<<max;
}