#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
#include<math.h>
#define MaxN 1003
ll t,n,h,r;
int fa[MaxN];
int top[MaxN];
int bot[MaxN];

inline void init__(int p){
    for(int i=1;i<=p;i++){
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
    int fu=find(u);
    int fv=find(v);
    fa[fv]=fa[fu];
}

struct node
{
    ll x,y,z;   
}in[MaxN];

int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>h>>r;
        init__(n);
        memset(top,0,sizeof(top));
        memset(bot,0,sizeof(bot));

        for(int s=1;s<=n;s++){
            cin>>in[s].x>>in[s].y>>in[s].z;
        }
        int tops=0;
        int bots=0;
        for(int p=1;p<=n;p++){
            if(in[p].z+r>=h){
                top[tops]=p;
                tops++;
            }
            if(in[p].z<=r){
                bot[bots]=p;
                bots++;
            }
            for(int q=p+1;q<=n;q++){
                //减小运算量的小妙招
                ll tmp=pow(in[p].x-in[q].x,2)+pow(in[p].y-in[q].y,2);
                if(tmp>4*r*r){
                    continue;
                }
                if(4.0*r*r>=tmp+pow(in[p].z-in[q].z,2)){
                    add(p,q);
                }
            }
        }

        bool flag=false;
        for(int p=0;p<tops;p++){
            for(int q=0;q<tops;q++){
                if(find(top[p])==find(bot[q])){
                    cout<<"Yes"<<endl;
                    flag=true;
                    break;
                }
            }
            /*
            这里寄了,忘记break只能出一个循环,导致答案行数增多
            */
            if(flag){
                break;
            }
        }
        if(!flag){
            cout<<"No"<<endl;
        }
    }
}