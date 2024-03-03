#include<iostream>
#include<math.h>

using namespace std;

int n,m;

typedef struct{
    int op;
    double v;
}op;

op ops[100003];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int o;
        double v;
        scanf("%d %lf", &o, &v);
        ops[i].op = o;
        ops[i].v = v;
    }

    for(int r=0;r<m;r++){
        int i,j;
        int ix,iy;
        scanf("%d %d %d %d", &i,&j,&ix,&iy);
        double x = ix, y = iy;

        double rt = 0; // 转过的角度
        double ks = 1; // 伸缩的大小
        for(int s=i;s<=j;s++){
            
            // if(ops[s].op==1){
            //     double v = ops[s].v;
            //     x = x * v;
            //     y = y * v;
            // }else{
            //     double v = ops[s].v;
            //     double ox = x, oy = y; // !!  大坑: 注意要保留原来的x去计算y
            //     x = ox*cos(v)-oy*sin(v);
            //     y = ox*sin(v)+oy*cos(v);
            // }

            // 直接计算会超时: 需要发现两个操作是互不干扰的特性
            if(ops[s].op==1){
                ks = ks * ops[s].v;
            }else{
                rt = rt + ops[s].v;
            }
        }

        // 汇总计算
        x = x * ks;
        y = y * ks;
        double ox = x, oy = y;
        x = ox*cos(rt)-oy*sin(rt);
        y = ox*sin(rt)+oy*cos(rt);
        printf("%lf %lf\n", x, y);
    }
}  