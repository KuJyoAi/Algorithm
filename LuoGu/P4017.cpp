#include<iostream>
#include<queue>
#include<cstring>
#define MaxN 5003
using namespace std;
int n,m;
int head[MaxN];
struct edge{
    int v,nxt;
}e[MaxN];
int ecnt=0;
int res[MaxN];
int indeg[MaxN],outdeg[MaxN];
void add(int u, int v){
    e[ecnt].v=v;
    e[ecnt].nxt=head[u];
    head[u]=ecnt;
    ecnt++;
}
int main(){
    cin>>n>>m;
    memset(head,-1,sizeof(head));
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        add(x,y);
        indeg[y]++;
        outdeg[x]++;
    }

    queue<int> st,ed;
    for(int i=1;i<=n;i++){
        if(!indeg[i]){
            st.push(i);
            res[i]=1;
        }else if(!outdeg[i]){
            ed.push(i);
        }
    }

    while(!st.empty()){
        int u=st.front();
        st.pop();
        for(int i=head[u];i!=-1;i=e[i].nxt){
            int v=e[i].v;
            indeg[v]--;
            if(!indeg[v]){
                st.push(v);
            }
            res[v]+=res[u];
        }
    }
    long long ans=0;
    while(!ed.empty()){
        ans+=res[ed.front()];
        ed.pop();
        ans%=80112002;
    }
    cout<<ans;
    return 0;
}