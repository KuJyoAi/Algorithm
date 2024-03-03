#include<iostream>
#include<queue>
#include<cstring>
/*
此处对bfs进行了一点优化,采用类似于dp的方法
res[v]+=res[u],继承了上一个的步数
并且对第二次访问的路径不再添加(否则会爆内存!)
*/
#define MaxN 1000003
#define MaxM 2000003
using namespace std;

int n,m;
int head[MaxN];
struct node{
    int v,next=-1;
}edge[MaxM];
int vis[MaxN];
int res[MaxN];
int cnt=0;

inline void add(int u, int v){
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    cnt++;
}

struct A
{
    int t,u;
};
queue<A> q;
int main(){
    memset(vis,0x3f,sizeof(vis));
    memset(head,-1,sizeof(head));
    memset(res,0,sizeof(res));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(a!=b){
            add(a,b);
            add(b,a);
        }    
    }

    q.push(A{0,1});
    res[1]=1;
    vis[1]=0;
    while(!q.empty()){
        int u=q.front().u;
        int t=q.front().t;
        q.pop();

        //cout<<" u:"<<u<<" t:"<<t<<endl;
        for(int i=head[u];i!=-1;i=edge[i].next){
            
            int v = edge[i].v;
            //cout<<"v:"<<v<<" u:"<<u<<" t:"<<t<<endl;
            if(vis[v]<t+1){
                continue;
            }else if(vis[v]==t+1){
                res[v]+=res[u];
                if(res[v]>100003){
                    res[v]-=100003;
                }
                //cout<<"res:"<<v<<" "<<res[v]<<endl;
            }else{
                vis[v]=t+1;
                //cout<<"vis:"<<v<<" "<<vis[v]<<endl;
                res[v]=res[u];
                if(res[v]>100003){
                    res[v]-=100003;
                }
                q.push(A{t+1,v});
            }
            
        }
    }

    for(int i=1;i<=n;i++){
        cout<<res[i]<<endl;
    }
}