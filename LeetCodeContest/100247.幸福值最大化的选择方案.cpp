#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;

long long maximumHappinessSum(vector<int>& happiness, int k) {
    sort(happiness.begin(),happiness.end());
    int t = 0;
    long long res = 0;
    for(int i = happiness.size()-1;i>=0;i--){
        if (t >= k || happiness[i] - t <= 0) {
            break;
        }

        res += happiness[i] - t;
        t++;
    }
    return res;
}
int main() {
    // happiness = [2,3,4,5], k = 1
    // 输出：5
    vector<int> happiness = {2,3,4,5};
    int k = 1;
    cout << maximumHappinessSum(happiness,k) << endl;
    return 0;
}