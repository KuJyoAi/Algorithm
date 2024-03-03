#include<iostream>
#include<queue>
using namespace std;

int n,m,k;
typedef struct{
	int t, c;
}node;

bool operator<(const node &n1, const node &n2){
	if (n1.t != n2.t){
		return n1.t < n2.t;
	}else{
		return n1.c > n2.c;
	}
}

priority_queue<node> q;

int main(){
	cin>>n>>m>>k;
	
	for(int i=0;i<n;i++){
		int t,c;
		scanf("%d %d",&t,&c);
		if(t>k){
			q.push(node{t,c});
		}
	}
	
	while(m>0 && !q.empty()){
		node n = q.top();
		q.pop();
//		cout<<"n:"<<n.t<<" "<<n.c<<"->";
		if (m >= n.c){
			m -= n.c;
			n.t--;
		}else{
			q.push(n);
			break;
		}
//		cout<<n.t<<" "<<n.c<<"|"<<m<<endl;
		if(n.t > k){
			q.push(n);
		}
	}
	
	if(q.empty()){
		cout<<k;
	}else{
		cout<<q.top().t;
	}	
		
}
