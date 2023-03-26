#include<iostream>
using namespace std;

void dfs(string mid,string beh){
    if(mid.size()==1){
        cout<<mid;
        return;
    }else if(!mid.size()) {
        return;
    }

    cout<<beh[beh.size()-1];
    int root=mid.find(beh[beh.size()-1]);
    
    dfs(mid.substr(0,root),beh.substr(0, root));
    dfs(mid.substr(root+1),beh.substr(root,beh.size()-root-1));
}
int main(){
    string mid;
    string beh;
    cin>>mid>>beh;
    dfs(mid,beh);
    return 0;
}