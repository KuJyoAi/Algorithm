#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
/*
 * 板子题目, 用动态规划, 设f[i]表示选取nums[i]的最长子序列
 * 转移方程的找法:
 * 从i-1往前找, 不妨设下标为j
 * 既然要选取nums[i], 那么只需要找到之前最大的f[j], 然后加上nums[i]
 * 当然, 需要满足nums[j]<nums[i]
 * 举例如下:
 * 10  9  2  5  3  7  101  18
 * 1   1  1  2  2  3  4    4
 * 
 * 但是输出的结果不是f[n-1], 因为选取了最后一个元素, 可能不一定是最大的
 * 例如:
 * 1 3 6 7 9 4 10 5 6
 * 1 2 3 4 5 3 6  4 5
 * 所以需要用maxans记录结果
 */
int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	int f[n];
	memset(f,0,sizeof(f));
	f[0]=1;
	int maxans = 1;
	for(int i=1;i<n;i++){
		f[i] = 1;
		
		for(int j=i-1;j>=0;j--){
			if(nums[j]<nums[i]){
				f[i] = max(f[i],f[j]+1);
			}
		}
		maxans = max(maxans, f[i]);
	}
	return maxans;
}

int main(){
	vector<int> v1 = {1,3,6,7,9,4,10,5,6};
	cout<<lengthOfLIS(v1)<<endl;
}
/*
 * 解法2:
 * 
 */
int lengthOfLIS2(vector<int>& nums) {
	int len = 1, n = (int)nums.size();
	if (n == 0) {
		return 0;
	}
	vector<int> d(n + 1, 0);
	d[len] = nums[0];
	for (int i = 1; i < n; ++i) {
		if (nums[i] > d[len]) {
			d[++len] = nums[i];
		} else {
			int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (d[mid] < nums[i]) {
					pos = mid;
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			d[pos + 1] = nums[i];
		}
	}
	return len;
}
