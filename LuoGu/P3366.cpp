#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define maxf 100005
#define maxn 5005
#define maxm 200005
struct edge{
    int u,v,w;
    bool operator>(const edge& e)const{
        return w>e.w;
    }
};
priority_queue<edge, vector<edge>, greater<edge>> q;
int n,m;
int fa[maxf];
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
inline void add(int u, int v){
    fa[find(v)]=find(u);
}
int main(){
    cin>>n>>m;
    init();
    
    priority_queue<edge, vector<edge>, greater<edge>> q;
   
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        q.push(edge{x,y,z});
    }

    int cntn=1;
    int wei=0;
    while(!q.empty()){
        int u=q.top().u;
        int v=q.top().v;
        int w=q.top().w;
        q.pop();
        if(find(u)==find(v)){
            continue;
        }
        cntn++;
        wei+=w;
        add(u,v);
    }

    if(cntn==n){
        cout<<wei;
    }else{
        cout<<"orz";
    }
    return 0;
}