#include <iostream>
#include <vector>
#include <numeric>
#include<set>

using namespace std;
bool splitArraySameAverage(vector<int> &nums);
int main(){
    vector<int> test = {3,1};
    if(splitArraySameAverage(test)){
        cout<<"true";
    }else{
        cout<<"false";
    }
}

bool splitArraySameAverage(vector<int> &nums){
    int n = nums.size();
    double avg = accumulate(nums.begin(),nums.end(), 0) * 1.0 / n;
    for(int &i : nums){
        i = (i  - avg)*2.0;
        cout<<i<<" ";
    }
    //状态
    set<int> vis;
    //枚举状态
    for(int status=1;status < 1<<(n/2);status++){
        int sum = 0;
        //求这个状态的和
        for(int i = 0;i<n/2;i++){
            if((status>>i)&1){
                sum += nums[i];
            }
        }
        if(sum==0){
            return true;
        }
        vis.insert(sum);
    }
    //枚举右状态
    int dx =1<<(n/2);
    for(int status=1<<(n/2);status <= 1<<n;status+=dx){
        int sum = 0;
        //求这个状态的和
        for(int i = n/2;i<n;i++){
            if((status>>i)&1){
                sum += nums[i];
            }
        }
        if(sum==0){
            return true;
        }
        if(vis.count(-sum)){
            return true;
        }
    }
    return false;
}