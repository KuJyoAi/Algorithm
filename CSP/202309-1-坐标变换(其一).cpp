#include<iostream>

using namespace std;

int n,m;
int main(){
    cin>>n>>m;
    int dx = 0;
    int dy = 0;
    for(int i=0;i<n;i++){
        int tx, ty;
        scanf("%d %d",&tx,&ty);
        dx += tx;
        dy += ty;
    }

    for(int i=0;i<m;i++){
        int x, y;
        scanf("%d %d",&x,&y);
        printf("%d %d\n",x+dx,y+dy);
    }
}