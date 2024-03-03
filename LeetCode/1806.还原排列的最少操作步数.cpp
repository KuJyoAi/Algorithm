#include<iostream>
#define N 6
using namespace std;

void Transform(int perm[N]){
    int arr[N];
    for(int i=0;i<N;i++){
        if(i%2==0){
            arr[i]=perm[i/2];
        }else{
            arr[i]=perm[N/2+(i-1)*2];
        }
    }
    for(int i=0;i<N;i++){
        perm[i]=arr[i];
        cout<<perm[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int perm[N];
    for(int i=0;i<N;i++){
        perm[i]=i;
    }
    while(getchar()!=EOF){
        Transform(perm);
    }
}