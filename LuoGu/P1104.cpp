#include<bits/stdc++.h>
using namespace std;
struct man{
	string name;
	int y,m,d,n;
};
struct man oi[103];
bool cmp(struct man m1,struct man m2);
int main(){
	int n=0;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>oi[i].name>>oi[i].y>>oi[i].m>>oi[i].d;
		oi[i].n=i;
	}
	
	sort(oi,oi+n,cmp);
	
	for(int i=0;i<n;i++){
		cout<<oi[i].name<<endl;
	}
}

bool cmp(struct man m1,struct man m2){
	if(m1.y==m2.y){
		if(m1.m==m2.m){
			if(m1.d==m2.d){
				//相等,输出靠后先输出,即交换顺序 
				return m1.n>m2.n;
			}else{
				return m1.d<m2.d;
			}
		}else{
			return m1.m<m2.m;
		}
	}else{
		return m1.y<m2.y;
	}
} 
	 
