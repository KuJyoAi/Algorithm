#include<iostream>
#define MaxN 1101
using namespace std;
int fr[2*MaxN];
int n,m;
int find(int x){
    if(fr[x]==x){
        return x;
    }else{
        fr[x]=find(fr[x]);
        return fr[x];
    }
}
void merge(int x, int y){
    int fx=find(x);
    int fy=find(y);
    fr[fx]=fy;
}
int main(){
    cin>>n>>m;

    for(int i=1;i<=2*n;i++){
        fr[i]=i;
    }

    for(int i=0;i<m;i++){
        char opt;
        int a, b;
        cin>>opt>>a>>b;

        if(opt=='F'){
            merge(a,b);
        }else{
            merge(a+n,b);
            merge(b+n,a);
        }
    }

    int res=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i){
            res++;
        }
    }
    cout<<res;
    return 0;
}