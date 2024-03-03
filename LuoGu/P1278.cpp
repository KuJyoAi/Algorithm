#include<iostream>
#include<vector>

using namespace std;
int n;
int dp[17][1<<17];
int siz[17];
string str[17];
vector<int> v[257];
//cond状态下选择nxt的dp最大值
int dfs(int nxt,int cond){
    if(dp[nxt][cond]){
        return dp[nxt][cond];
    }

    int ans=0;

    for(auto u:v[(int)str[nxt][siz[nxt]-1]]){
        if(!(cond>>(u-1)&1)){
            ans=max(ans,dfs(u,cond|1<<(u-1)));
        }
    }

    dp[nxt][cond]=ans+siz[nxt];
    return dp[nxt][cond];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str[i];
        siz[i]=str[i].size();
        v[(int)str[i][0]].push_back(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dfs(i,1<<(i-1)));
    }
    cout<<ans;
}