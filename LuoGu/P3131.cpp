#include<iostream>
#include<cstring>
#define maxN 50001
using namespace std;
int a[maxN];

int main(){
    int n;
    cin>>n;
    a[0]=0;

    for(int i=1;i<=n;i++){
       int s;
       cin>>s;
       a[i]=(a[i-1]+s)%7;
    }

    //找余数相同的,存储最大最小的下标
    int s[7],e[7];
    memset(s,0x3f, sizeof(s));
    memset(e,0, sizeof(e));
    for(int i=1;i<=n;i++){
        if(s[a[i]]>i){
            s[a[i]]=i; 
        }

        if(e[a[i]]<i){
            e[a[i]]=i;
        }
    }

    int max_ = 0;
    for(int i=0;i<7;i++){
        max_ = max(max_, e[i]-s[i]);
    }

    cout<<max_;
}