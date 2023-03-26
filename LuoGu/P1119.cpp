#include<iostream>
#include<cstring>
#define MaxN 203
#define MaxQ 50003

using namespace std;
int f[MaxN][MaxN];
int n,m,q;
int t[MaxN];
inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

/*
floyd算法模板:
用领接矩阵存图
写一个update函数(inline)
把k看做中继节点,从而能够控制哪些节点出现哪些不出现
update(k)是以k为中继,去松弛各节点
如果需要存储状态,则把f定义为三维数组即可
*/
inline void update(int k){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
    }
}

int main(){
    memset(f,0x3f,sizeof(f));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        t[i]=read();
        //cin>>t[i];
        f[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b,w;
        a=read();
        b=read();
        w=read();
        //cin>>a>>b>>w;
        a++;
        b++;

        f[a][b]=w;
        f[b][a]=w;
    }
    cin>>q;
    int k=1;
    for(int a=0;a<q;a++){
        int p,q,r;
        p=read()+1;
        q=read()+1;
        r=read();

        while(t[k]<=r&&k<=n){
            update(k);
            k++;
        }

        if(r>=max(t[p],t[q]) && f[p][q]!=0x3f3f3f3f){
            cout<<f[p][q]<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}