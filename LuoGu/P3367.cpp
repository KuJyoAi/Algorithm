#include<iostream>
using namespace std;
#define maxN 100001
int fa[maxN];
int n;
int m;
int find(int x){
    if(fa[x]==x){
        return x;
    }else{
        fa[x]=find(fa[x]);
        return fa[x];
    }
}
void merge(int i, int j){
    int fi=find(i);
    int fj=find(j);
    fa[fi]=fj;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }

    for(int i=0;i<m;i++){
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1){
            merge(x,y);
        }else{
            if(find(x)==find(y)){
                cout<<'Y'<<endl;
            }else{
                cout<<'N'<<endl;
            }
        }
    }
}