#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
/*
 * 显然又是动态规划
 * 回想最长递增子序列的动态规划, 是一维的, 因为它不需要考虑公差
 * 因此我们用二维的表示公差
 * f[i][j]表示num[i]结尾的, 公差为j的结果
 * 由于公差可能为负, 这里把公差偏移一下变成正数
 * 
 * 转移方程:
 * f[i][j] = max(f[i][j],f[k][j]+1), 0<=j<=i-1
 */
int longestArithSeqLength(vector<int>& nums) {
	int n = nums.size();
	int f[n][1001];
	memset(f, 0, sizeof(f));
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		for (int k = 0; k < i; ++k) {
			int j = nums[i] - nums[k] + 500;
			f[i][j] = max(f[i][j], f[k][j] + 1);
			ans = max(ans, f[i][j]);
		}
	}
	return ans + 1;
}

int main(){
	vector<int> test = {9,4,7,2,10};
	cout<<longestArithSeqLength(test);
	return 0;
}
