#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define maxn 100005
#define inf 0x3f
int n,m,s;
//dijkstra算法最短路问题
struct edge{
    int v,w;
};
struct node {
  int dis, u;
  bool operator>(const node& a) const { return dis > a.dis; }
};
int dis[maxn],vis[maxn];
vector<edge> e[maxn];
priority_queue<node, vector<node>, greater<node> > q;
void dijkstra(int s){
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        //防止往回访问
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(auto ed : e[u]){
            int v=ed.v,w=ed.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
int main(){
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back(edge{v,w});
    }
    memset(dis,inf,sizeof(dis));
    dijkstra(s);
    for(int i=1;i<=n;i++){
        //无穷大修正
        if(dis[i]==1061109567){
            dis[i]=2147483647;
        }
        cout<<dis[i]<<" ";
    }
}