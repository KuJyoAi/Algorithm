#include<iostream>
#define MaxL 100003
using namespace std;
int a[MaxL];
int b[MaxL];
int pos[MaxL],dp[MaxL];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        pos[b[i]]=i;
    }

    dp[1]=pos[a[1]];
    int len=1;
    for(int i=2;i<=n;i++){
        //注意此处, dp存储的是下标而不是值,故在比较时a[i]要用pos套上而dp不用
        
        if(pos[a[i]]>dp[len]){
            dp[++len]=pos[a[i]];
        }else{
            int l=1,r=len,mid;
            while(l<r){
                mid=(l+r)>>1;
                if(pos[a[i]]<dp[mid]){
                    r=mid;
                }else{
                    l=mid+1;
                }
            }
            dp[l]=pos[a[i]];
        }
    }
    cout<<len;
}