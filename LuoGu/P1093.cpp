#include<bits/stdc++.h>
using namespace std;
bool cmp(struct st st1,struct st st2);
struct st{
	int c,m,e,num,all;
};
int n;
struct st sts[301];
int main(){
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>sts[i].c>>sts[i].m>>sts[i].e;
		sts[i].num=i+1;
		sts[i].all=sts[i].c+sts[i].m+sts[i].e;
	}
	sort(sts,sts+n,cmp);
	for(int i=0;i<5;i++){
		cout<<sts[i].num<<" "<<sts[i].all<<endl;
	}
	return 0;
}
bool cmp(struct st st1,struct st st2){
	if(st1.all!=st2.all){
		return st1.all>st2.all;
	}else if(st1.c!=st2.c){
		return st1.c>st2.c;
	}else {
		return st1.num<st2.num;
	}
}
