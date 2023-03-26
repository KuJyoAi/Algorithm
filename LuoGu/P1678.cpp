#include<iostream>
#include<algorithm>
using namespace std;
int stu[100000];
int scr[100000];
int m,n;//school,student
int solve(int s);
int main(){
	cin>>m>>n;
	for(int i=0;i< m;i++){
		//TODO
		cin>>scr[i];
	}
	for(int i=0;i< n;i++){
		cin>>stu[i];
	}
	sort(scr,scr+m);
	
	int res=0;
	for(int s=0;s< n;s++){
		//TODO
		res += solve(s);
	}
	cout<<res;
	return 0;
}

int solve(int i){
	int l=0,r=m-1,mid=(l+r)/2;
	while(abs(l-r)>1){
		//TODO
		if(scr[mid]>stu[i]){
			//TODO
			r=mid;
		}else{
			l=mid;
		}
		mid=(l+r)/2;
	}
	
	//cout<<"l:"<<scr[l]<<"\tr:"<<scr[r]<<"\tstu:"<<stu[i]<<endl;
	int t1=abs(scr[l]-stu[i]);
	int t2=abs(scr[r]-stu[i]);
	return t1<t2?t1:t2;
}
