#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int,bool> br;
int t,n;
inline int read()
{
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}
int main(){
    cin>>t;

    for(int i=0;i<t;i++){
        cin>>n;
        br.clear();
        for(int q=0;q<n;q++){
            int a;
            a=read();
            if(!br[a]){
                cout<<a<<" ";
                br[a]=1;
            }
        }
        cout<<endl;
    }
}