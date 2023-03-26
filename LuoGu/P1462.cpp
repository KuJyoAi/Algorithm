#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 10005
#define maxMon 1000000005;
int mid;//二分分界
int lf=0x3f,rg;//最小值最大值
struct edge{
    int v,w;
};
int dis[maxn],vis[maxn],mon[maxn];
vector<edge> e[maxn];
struct node{
    int dis,u;
    bool operator>(const node& a)const{
        return dis>a.dis;
    }
};
int n,m,b;
priority_queue<node,vector<node>, greater<node> > q;
inline int read(){
	int sum=0;char a=getchar();
	while(a<'0'||a>'9')a=getchar();
	while(a>='0'&&a<='9'){
		sum=(sum<<3)+(sum<<1)+a-'0';
		a=getchar();
	}
	return sum;
}

void dijkstra(){
    //起点或终点过不了
    if(mid<mon[1]||mid<mon[n]){
        dis[n]=0x3f3f3f3f;
        return ;
    }
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));

    dis[1]=0;
    q.push(node{0,1});
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        //去除高收费和访问过的
        if(vis[u]||mon[u]>mid){
            continue;
        }
        vis[u]=1;
        for(auto ed:e[u]){
            int v=ed.v,w=ed.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                
            }
            q.push(node{dis[v],v});
        }
    }
}
int main(){
    //std::ios::sync_with_stdio(false);
    n=read();
    m=read();
    b=read();
    //cin>>n>>m>>b;
    for(int i=1;i<=n;i++){
        //int tmp;
        mon[i]=read();
    }
    int t1,t2,t3;
    for(int i=1;i<=m;i++){
        //scanf("%d %d %d",&a,&b,&c);
        t1=read();
        t2=read();
        t3=read();
        e[t1].push_back({t2,t3});
        e[t2].push_back({t1,t3});
    }
    //最大值失败
    mid=maxMon;
    dijkstra();
    if(dis[n]>b){
        //cout<<"no!";
        //cout<<mid;
        cout<<"AFK";
        return 0;
    }
    lf=1;
    rg=maxMon;
    while(rg-lf>1){
        mid=(lf+rg)>>1;
        dijkstra();
        //cout<<"lf"<<lf<<" rg"<<rg<<endl;
        //cout<<"mid="<<mid<<" dis="<<dis[n]<<endl;
        if(dis[n]>b){
            //不能到达,放宽
            lf=mid;
        }else{
            //可达,收紧
            rg=mid;
        }
        //cout<<"mid:"<<mid<<endl;
    }
    //cout<<"res:"<<" rg="<<rg<<" lf="<<lf<<" mid="<<mid;
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