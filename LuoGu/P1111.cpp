#include<iostream>
#include<algorithm>
#define MaxN 1003
#define MaxM 100003
using namespace std;
int fa[MaxN];
int find(int x){
    if(fa[x]==x){
        return x;
    }else{
        fa[x]=find(fa[x]);
        return fa[x];
    }
}
void merge(int x,int y){
    int fx=fa[x];
    int fy=fa[y];
    fa[fx]=fa[fy];
}
int n,m;
struct node{
    int x, y, t;
}in[MaxM];

bool cmp(node a, node b){
    return a.t<b.t;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    

    int times=1;
    for(int i=0;i<m;i++){
        cin>>in[i].x>>in[i].y>>in[i].t;
    }

    sort(in,in+m,cmp);

    for(int i=0;i<m;i++){
        int x=in[i].x;
        int y=in[i].y;

        if(find(x)!=find(y)){
            merge(x,y);
            times++;
            if(times==n){
                cout<<in[i].t;
                return 0;
            }
        }
    }

    cout<<-1;
    return 0;
}