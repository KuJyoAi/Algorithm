#include<bits/stdc++.h>
using namespace std;
bool cmp(struct man m1,struct man m2);
struct man{
	int n,t;
};
struct man m[1003];
int main(){
	int n;
	cin>>n;
	double avg=0;
	for(int i=0;i<n;i++){
		cin>>m[i].t;
		m[i].n=i+1;
	};
	sort(m,m+n,cmp);
	for(int i=0;i<n;i++){
		cout<<m[i].n<<" ";
		avg+=(n-i-1)*m[i].t;//坑!!!接水的人不算等待时间(他没在等待)
	}
	cout<<endl;
	printf("%.2f",avg/n);
}

bool cmp(struct man m1,struct man m2){
	if(m1.t!=m2.t){
		return m1.t<m2.t;
	}else{
		return m1.n<m2.n;
	}
}
