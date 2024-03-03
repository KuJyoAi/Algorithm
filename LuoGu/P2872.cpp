#include<iostream>
#include<queue>
#include<cstring>
#include<math.h>
using namespace std;
#define MaxN 1003
int fa[MaxN];
struct Edge{
    int u,v;
    double w;
    bool operator>(const Edge& a)const{
        return w>a.w;
    }
};
int vis[MaxN][MaxN];

int n,m;
inline void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}
inline int find(int x){
    if(fa[x]==x){
        return x;
    }else{
        fa[x]=find(fa[x]);
        return fa[x];
    }
}
inline void add(int x,int y){
    fa[find(x)]=fa[find(y)];
}
int xp[MaxN],yp[MaxN];
int main(){
    cin>>n>>m;
    init();

    for(int i=1;i<=n;i++){
        cin>>xp[i]>>yp[i];
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        vis[x][y]=1;
        vis[y][x]=1;
    }

    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    for(int a=1;a<=n;a++){
        for(int b=a+1;b<=n;b++){
            if(vis[a][b]){
                q.push(Edge{a,b,0.0});
                continue;
            }
            double res=(xp[a]-xp[b]+0.0)*(xp[a]-xp[b]+0.0)+(yp[a]-yp[b]+0.0)*(yp[a]-yp[b]+0.0);
            q.push(Edge{a,b,res});
        }
    }

    int cnt=1;
    double res=0;;
    while(cnt<n){
        int u=q.top().u;
        int v=q.top().v;
        double w=q.top().w;
        q.pop();
        if(find(u)==find(v)){
            continue;
        }
        res+=sqrt(w);
        add(u,v);
        cnt++;
    }

    printf("%.2f",res);
}