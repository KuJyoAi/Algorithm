//用链式前向星实现
//inline yyds
#include<iostream>
#include<queue>
#include<cstring>

#define MaxMon 1000000003
#define MaxN 100005
#define MaxM 500005

using namespace std;
int n,m,b;
int lf=1,rg=MaxMon,mid=MaxMon;
int head[MaxN];
int dis[MaxN], vis[MaxN], cost[MaxN];
struct Edge{
    int v,w,next=-1;
}edge[MaxM];

struct Node{
    int dis,u;
    bool operator>(const Node& a)const{
        return dis>a.dis;
    }
};
priority_queue<Node, vector<Node>, greater<Node>> q;
int ecnt = 0;//边数

void add(int u, int v, int w){
    edge[ecnt].v=v;
    edge[ecnt].w=w;
    edge[ecnt].next=head[u];
    head[u]=ecnt;
    ecnt++;
}

inline int read(){
	int sum=0;char a=getchar();
	while(a<'0'||a>'9')a=getchar();
	while(a>='0'&&a<='9'){
		sum=(sum<<3)+(sum<<1)+a-'0';
		a=getchar();
	}
	return sum;
}

inline void dijkstra(){
    if(cost[1]>mid||cost[n]>mid){
        dis[n]=0x3f3f3f3f;
        return ;
    }

    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));

    dis[1]=0;
    q.push(Node{0,1});

    while(!q.empty()){
        int u=q.top().u;
        q.pop();

        if(vis[u]||mid<cost[u]){
            continue;
        }
        vis[u]=1;

        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            int w=edge[i].w;
            
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
            }

            q.push(Node{dis[v],v});
        }
    }   
}

int main(){
    memset(head,-1,sizeof(head));
    cin>>n>>m>>b;

    for(int i=1;i<=n;i++){
        //cin>>cost[i];
        cost[i]=read();
    }

    for(int i=1;i<=m;i++){
        int a,b,c;
        //cin>>a>>b>>c;
        a=read();
        b=read();
        c=read();
        add(a,b,c);
        add(b,a,c);
    }

    dijkstra();
    if(dis[n]>b){
        cout<<"AFK";
        return 0;
    }

    while(rg-lf>1){
        mid=(lf+rg)>>1;

        dijkstra();
        if(dis[n]>b){
            //不能到达,放宽
            lf=mid;
        }else{
            //可达,收紧
            rg=mid;
        }
    }

    if(lf==rg){
        cout<<mid;
    }else{
        if(lf==mid&&dis[n]>b){
            cout<<mid+1;
        }else if(rg==mid){
            mid--;
            dijkstra();
            if(dis[n]>b){
                cout<<++mid;
            }else{
                cout<<mid;
            }
        }
    }

    return 0;
}