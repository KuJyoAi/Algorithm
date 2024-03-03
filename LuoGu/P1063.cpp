#include<iostream>
#define maxn 103
#define ll long long
using namespace std;
int n;
int power[2*maxn];
ll dp[2*maxn][2*maxn];
ll dfs(int i,int j){
    if(dp[i][j]){
        return dp[i][j];
    }

    if(j-i==1){
        dp[i][j]=power[i]*power[j]*power[j+1];
    }

    ll ans=0;
    for(int k=i;k<j;k++){
        ans=max(ans,dfs(i,k)+dfs(k+1,j)+power[i]*power[k+1]*power[j+1]);
    }

    dp[i][j]=ans;
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>power[i];
        power[i+n]=power[i];
    }
    power[2*n+1]=power[1];

    ll ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dfs(i,i+n-1));
    }
    cout<<ans;
}