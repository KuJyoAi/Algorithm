#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    string text;
    cin>>text;
    int cnt[5];
    memset(cnt,0,sizeof(cnt));
    for (int i = 0; i < text.length(); i++)
    {
        char t = text[i];
        if (t == 'a'){
            cnt[1]++;
        }
        else if (t == 'b'){
            cnt[0]++;
        }
        else if (t == 'l'){
            cnt[2]++;
        }
        else if (t == 'o'){
            cnt[3]++;
        }
        else if (t == 'n'){
            cnt[4]++;
        }
    }
    int max = 0x7fffffff;
    cnt[2] /= 2;
    cnt[3] /= 2;
    for (int i = 0; i < 5; i++){
        //cout<<cnt[i]<<" ";
        if (cnt[i] < max){
            max = cnt[i];
        }
    }
    cout << max;
    return 0;
}