#include<bits/stdc++.h>
using namespace std;
bool cmp(struct coin c1,struct coin c2);
struct coin{
	int w,v;
	double b;//��:��ֵ/���� 
};
struct coin c[103];
int main(){
	int n,t;
	cin>>n>>t;
	for(int i=0;i<n;i++){
		cin>>c[i].w>>c[i].v;
		c[i].b=((double)c[i].v/c[i].w);// *1.0���ӻ�run error,��֪��Ϊʲô? 
	}
	
	sort(c,c+n,cmp);
	
	double v;//������ֵ 
	for(int i=0;i<n;i++){
		if(t-c[i].w>0){
			t-=c[i].w;
			v+=c[i].v;
		}else{
			v+=t*c[i].b;
			break;
		}
	}
	printf("%.2lf",v);
}

bool cmp(struct coin c1,struct coin c2){
	return c1.b>=c2.b;
}
