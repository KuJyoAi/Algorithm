#include<iostream>
#include<queue>
#include<utility>
using namespace std;
int n=0;
int a[100003];
int b[100003];
int pos[100003];//表示b的数组对a的下标
pair<int,int> p;

int main(){
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        pq.push(pair<int,int>(a[0]+b[i],i));
    }

    for(int i=0;i<n;i++){
        pair<int, int> tmp = pq.top();
        pq.pop();
        cout<<tmp.first<<" ";
        
        //cout<<tmp.first<<" "<<tmp.second<<" "<<i<<" "<<pos[tmp.second]<<endl;
        pos[tmp.second]++;
        if(pos[tmp.second]==n){
            i--;
            continue;
        }
        pq.push(pair<int, int>(a[pos[tmp.second]]+b[tmp.second],tmp.second));
        
    }
    
    return 0;
}