#include<bits/stdc++.h>
using namespace std;
struct p{
	int x;
	int y;
	int z;
};
struct p ps[50001];
int n=0;
bool cmp(struct p p1,struct p p2);
int main(){
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>ps[i].x>>ps[i].y>>ps[i].z;
	}
	
	sort(ps,ps+n,cmp);
	double res;
	for(int i=0;i<n-1;i++){
		res+=sqrt(pow(ps[i].x-ps[i+1].x,2)+pow(ps[i].y-ps[i+1].y,2)+pow(ps[i].z-ps[i+1].z,2));
	}
	printf("%.3f",res);
}
bool cmp(struct p p1, struct p p2){
	if(p1.z<p2.z){
		return true;
	}
	return false;
}
