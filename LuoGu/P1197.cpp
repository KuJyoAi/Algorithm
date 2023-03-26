#include<iostream>
#include<vector>
using namespace std;
#define MaxN 100005
#define MaxM 200005
int n,m;
int fa[MaxN];
int x[MaxM],y[MaxM];
vector<int> edge[MaxN];
int dis[MaxN];
int isdis[MaxN];
int res[MaxM];
int find(int x){
    if(fa[x]==x){
        return x;
    }else{
        fa[x]=find(fa[x]);
        return fa[x];
    }
}
void merge(int x, int y){
    int fx=find(x);
    int fy=find(y);
    fa[fx]=fy;
}
void init(){
    for(int i=0;i<n;i++){
        fa[i]=i;
    }
}


int main(){
    cin>>n>>m;
    init();
    for(int i=0;i<m;i++){
        cin>>x[i]>>y[i];
        edge[x[i]].push_back(i);
        edge[y[i]].push_back(i);
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>dis[i];
        isdis[dis[i]]++;
    }

    //修一遍没有被摧毁的
    for(int p=0;p<n;p++){
        if(!isdis[p]){
            for(auto a:edge[p]){
                if(!isdis[x[a]] && !isdis[y[a]]){
                    merge(x[a],y[a]);
                }
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        if(fa[i]==i){
            res++;
        }
    }
    cout<<res-k<<endl;

    //反向修被摧毁的
    for(int i=k-1;i>=0;i--){
        int p=dis[i];
        isdis[dis[i]]=0;
        for(auto a:edge[p]){
            if(!isdis[x[a]] && !isdis[y[a]]){
                merge(x[a],y[a]);
            }
        }

        int res=0;
        for(int i=0;i<n;i++){
            if(fa[i]==i){
                res++;
            }
        }
        cout<<res-i<<endl;
    }
    return 0;
}