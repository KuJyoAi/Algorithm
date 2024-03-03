#include <iostream>
#include "queue"
using namespace std;
#define MaxN 2*100
#define INF 0x3f3f3f3f
int deg[MaxN]={0}; //入度
int res[MaxN]={0};
struct edge{
    int v = 0;
    edge* next = nullptr;
};
struct node{
    edge* next = nullptr;
};
node Vertex[MaxN];
void add(int u, int v){
    edge* e = (edge *)malloc(sizeof(edge));
    e->v=v;
    e->next=Vertex[u].next;
    Vertex[u].next = e;
}
int n,m;
int main() {
    queue<int> q;
    int a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        add(a,b);
        deg[b]++;
    }
    int num=0;
    for(int i=1;i<=n;i++){
        if(deg[i]==0){
            q.push(i);
            res[num] = i;
            num++;
        }
    }
    while(!q.empty()){
        int i=q.front();
        q.pop();
        edge *e = Vertex[i].next;
        while(e!=nullptr){
            deg[e->v]--;
            if(deg[e->v]==0){
                q.push(e->v);
                res[num] = e->v;
                num++;
            }
            e = e->next;
        }
    }
    if(n==num){
        for(int i=0;i<n-1;i++){
            cout<<res[i];
        }
        cout<<res[n-1];
    }else{
        cout<<-1;
    }
}
// 64 位输出请用 printf("%lld")