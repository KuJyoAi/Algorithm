#include<iostream>
using namespace std;
//因为只需要前序遍历,故用l,r存储左右节点
int n,root,l[128],r[128];
void dfs(int par){
    if(par=='*'){
        return;
    }
    cout<<(char)par;
    dfs(l[par]);
    dfs(r[par]);
}
int main(){
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        l[s[0]]=s[1];
        r[s[0]]=s[2];
        if(!root){
            root=s[0];
        }
    }
    dfs(root);
}