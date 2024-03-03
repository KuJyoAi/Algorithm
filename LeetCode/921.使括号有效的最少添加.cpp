#include<iostream>
#include<stack>

using namespace std;

int minAddToMakeValid(string s) {
    stack<char> bracks;
    for(auto i:s){
        if(!bracks.empty()){
            char c = bracks.top();
            if(c=='('&&i==')'){
                bracks.pop();
            }else{
                bracks.push(i);
            }
        }else{
            bracks.push(i);
        }
    }
    return bracks.size();
}

int main(){
    string s = "()))((";
    cout<<minAddToMakeValid(s);
}