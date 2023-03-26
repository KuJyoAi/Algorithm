#include<iostream>
#include<cstring>

#define maxN 103
using namespace std;

int dp_ma[2*maxN][2*maxN]={0};
int dp_mi[2*maxN][2*maxN]={0};
int sum[2*maxN];
int n;
int score[2*maxN];



int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>score[i];
        score[i+n]=score[i];
        sum[i]=sum[i-1]+score[i];
        ;
    }
    for(int i=1;i<=n;i++){
        sum[i+n]=sum[i+n-1]+score[i];
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i<=2*n-1;i++){
            int j=i+len-1;
            if(j>2*n){
                continue;
            }
            int loc_max=0;
            int loc_min=0x3f3f3f3f;
             for(int k=i;k<j;k++){
                loc_max=max(dp_ma[i][k]+dp_ma[k+1][j],loc_max);
                loc_min=min(dp_mi[i][k]+dp_mi[k+1][j],loc_min);
                
            }
            dp_ma[i][j]=loc_max+sum[j]-sum[i-1];
            dp_mi[i][j]=loc_min+sum[j]-sum[i-1];
        }
    }

    int ma=0,mi=0x7f7f7f7f;
    for(int i=1;i<=n;i++){
        if(ma<dp_ma[i][i+n-1]){
            ma=dp_ma[i][i+n-1];
        }
        if(mi>dp_mi[i][i+n-1]){
            mi=dp_mi[i][i+n-1];
        }
    }
    cout<<mi<<endl<<ma;
}