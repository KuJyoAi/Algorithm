#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<char> start = {'L','L','r'};
    vector<char> end = {'R','R','L'};
    int n = start.size();
        int i=-1,j=-1;
        while(i<n && j<n){
            do{
                i++;
            }while(i<n&&(start[i]!='R'&&start[i]!='L'));
            do{
                j++;
            }while(j<n&&(end[j]!='R'&&end[j]!='L'));
            cout<<i<<' '<<j;
            
            if(start[i]!=end[j]){
                return false;
            }
        }
        return true;
}