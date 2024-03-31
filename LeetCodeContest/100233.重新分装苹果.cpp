#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    int sum = accumulate(apple.begin(),apple.end(),0);
    sort(capacity.begin(),capacity.end());

    // 从大到小贪心
    int res = 0;
    for(int i = capacity.size()-1;i>=0;i--){
        if(sum<=capacity[i]){
            res++;
            break;
        }
        sum -= capacity[i];
        res++;
    }
    return res;
}
int main() {
    
    
    return 0;
}