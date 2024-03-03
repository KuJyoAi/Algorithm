#include<iostream>
#include<cstring>
using namespace std;
int N=0;
int m,k;
int num=1;
int g[305][305];
void check(){
    for(int x=0;x<m;x++){
        for(int y=x+1;y<m;y++){
            bool flag1=false;
            for(int z=0;z<m;z++){
                if(g[x][z]&&g[y][z]){
                    flag1=true;
                }else if(flag1){
                    cout<<"Case #"<<num<<": No"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"Case #"<<num<<": Yes"<<endl;
    return;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>m>>k;
        for(int p=0;p<k;p++){
            int x,y;
            cin>>x>>y;
            g[x][y]=1;
        }
        check();
        memset(g,0,sizeof(g));
        num++;
    }
    return 0;
}