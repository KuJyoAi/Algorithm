#include<iostream>
#include<string.h>
using namespace std;
#define maxn 100003 //边最大数
#define maxh 100003 //节点最大数
/*
思路:反向建图,从大到小遍历
模板学习
链式前向星
*/
int N,M;
int cnt=0;//eadg计数,存边用
int res[maxh];

//链式前向星
int head[maxh];
struct node{
    int to,next;
}graph[maxn];

void add(int sat, int end){
    //u→v
    graph[cnt].to=end;
    graph[cnt].next=head[sat];
    head[sat]=cnt;
    cnt++;
}

//搜索比较巧妙,是搜索边,sat是起点,用来赋值,end是边的尾部
void dfs(int sat,int end){
    if(res[end]!=0){
        return;
    }

    res[end]=sat;
      
    //遍历下一个节点的所有邻接节点
    for(int i=head[end];i!=-1;i=graph[i].next){
        
        dfs(sat,graph[i].to);
    }
    
}
int main(){
    memset(head,-1,sizeof(head));
    memset(res,0,sizeof(res));
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        add(v,u);
    }
    

    for(int i=N;i>0;i--){
        dfs(i,i);
    }

    for(int i=1;i<=N;i++){
        cout<<res[i]<<" ";
        //cout<<graph[head[i]].to<<endl;
    }

    return 0;
}