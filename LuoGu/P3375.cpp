#include<iostream>
using namespace std;
int next_[1000011];
string str,sub;
int lstr,lsub;
void init(){
    int j=0,k=-1;
    next_[0]=-1;
    while(j<lsub){
        if(k==-1||sub[j]==sub[k]){
            k++;
            j++;
            next_[j]=k;
        }else{
            k=next_[k];
        }
    }
}

void kmp(){
    int i=0,j=0;
    while(i<lstr){
        if(j==-1||str[i]==sub[j]){
            i++;
            j++;
        }else{
            j=next_[j];
        }

        if(j==lsub){
            i=i-j;
            cout<<i+1<<" "<<endl;
            j=-1;
        }
    }
}

int main(){
    cin>>str>>sub;
    lstr=str.length();
    lsub=sub.length();
    init();
    kmp();
    for(int i=1;i<=lsub;i++){
        cout<<next_[i]<<" ";
    }
}