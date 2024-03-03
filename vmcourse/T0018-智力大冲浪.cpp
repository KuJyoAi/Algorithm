#include<iostream>
#include<algorithm>
using namespace std;

int m,n;
typedef struct{
	int cost,date;
}T;
T t[505];
bool flag[505];
bool operator<(const T t1, const T t2){
	return t1.cost>t2.cost;
}
int main(){
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++) scanf("%d", &t[i].date);
	for(int i=1;i<=n;i++) scanf("%d", &t[i].cost);
	
	sort(t+1,t+n+1);
	
	
	
	for(int i=1;i<=n;i++){
		bool f=false;
		for(int j=t[i].date;j>=1;j--){
			// 从这个任务往前查
			if(!flag[j]){
				// 找到空位
				flag[j]=true;
				f = true;
				break;
			}
		}
		if(!f){
			// 没有找到空位
			m-=t[i].cost;
		}
	}
	printf("%d",m);
}
