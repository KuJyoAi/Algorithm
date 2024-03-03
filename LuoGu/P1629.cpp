#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 100003
//dijkstra
//大聪明:反向建图跑回去的路程
int res;
struct edge{
    int v,w;
};
struct node{
    int dis,u;
    bool operator>(const node& a) const{
        return dis>a.dis;
    }
};
vector<edge> e1[maxn];
vector<edge> e2[maxn];
int dis[maxn],vis[maxn];
priority_queue<node, vector<node>, greater<node> > q;

int n,m;
void dijkstra1(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));

    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(auto ed:e1[u]){
            int v = ed.v,w=ed.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
            }
            q.push({dis[v],v});
        }
    }
}
void dijkstra2(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));

    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(auto ed:e2[u]){
            int v = ed.v,w=ed.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
            }
            q.push({dis[v],v});
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e1[u].push_back({v,w});
        e2[v].push_back({u,w});
    }
    dijkstra1(1); 
    for(int i=1;i<=n;i++){
        //cout<<dis[i]<<" ";
        res+=dis[i];
    }  
    dijkstra2(1);
    for(int i=1;i<=n;i++){
        //cout<<dis[i]<<" ";
        res+=dis[i];
    }  
    cout<<res;
}