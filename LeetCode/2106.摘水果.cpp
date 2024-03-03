#include<iostream>
#include<vector>
using namespace std;

int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
	int left = 0;
	int right = 0;
	int n = fruits.size();
	int sum = 0;
	int ans = 0;
	
	auto step = [&](int left, int right) -> int {
		if (fruits[right][0] <= startPos) {
			return startPos - fruits[left][0];
		} else if (fruits[left][0] >= startPos) {
			return fruits[right][0] - startPos;
		} else {
			return min(abs(startPos - fruits[right][0]), abs(startPos - fruits[left][0])) + \
			fruits[right][0] - fruits[left][0];
		}
	};
	
	// 每次固定住窗口右边界
	while (right < n) {
		sum += fruits[right][1];
		// 移动左边界
		while (left <= right && step(left, right) > k) {
			sum -= fruits[left][1];
			left++;
		}
		ans = max(ans, sum);
		right++;
	}
	return ans;
}

int main(){
	vector<vector<int>> test = {{2,8},{6,3},{8,6}};
	cout<<maxTotalFruits(test, 5, 4);
	return 0;
}
