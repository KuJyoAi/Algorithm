#include<iostream>
#include<math.h>

using namespace std;

int n,m;

typedef struct{
    double k;
    double r;
}op;

op ops[100003];

// 直接计算会超时: 需要发现两个操作是互不干扰的特性, 也就是说可以计算"前缀和"

int main(){
    cin>>n>>m;
    ops[0].k = 1;
    ops[0].r = 0;
    for(int i=1;i<=n;i++){
        int o;
        double v;
        scanf("%d %lf", &o, &v);
        if(o==1){
            ops[i].k = ops[i-1].k * v;
            ops[i].r = ops[i-1].r;
        }else{
            ops[i].k = ops[i-1].k;
            ops[i].r = ops[i-1].r + v;
        }
    }

    for(int r=0;r<m;r++){
        int i,j;
        double x, y;
        scanf("%d %d %lf %lf", &i,&j,&x,&y);
        

        double rt = ops[j].r - ops[i-1].r;
        double ks = ops[j].k / ops[i-1].k;

        // 汇总计算
        x = x * ks;
        y = y * ks;
        double ox = x, oy = y;
        x = ox*cos(rt)-oy*sin(rt);
        y = ox*sin(rt)+oy*cos(rt);
        printf("%lf %lf\n", x, y);
    }
}  