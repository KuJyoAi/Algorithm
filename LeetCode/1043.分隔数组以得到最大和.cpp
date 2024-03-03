#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
/*
 * 思路: 由于下一个分组依赖于之前的分组, 只能用动态规划
 * 转移方程: 假设f[i]为前i个元素的最大分组的结果, 编号从1开始
 * 需要枚举的情况主要是: 最后一组分多少的问题
 * 如: f[i-1] + arr[i]
 * 	   f[i-2] + max(arr[i], arr[i-1])
 * 	   ......
 *     f[i-k] + max(arr[i], arr[i-1] ... arr[i-k-1])
 * 如此一来就能写出转移方程了
 * 代码是递推的解法, 故i从1开始, 也可以改写成递归
 */
int maxSumAfterPartitioning(vector<int>& arr, int k) {
	int n = arr.size();
	int f[n + 1];
	memset(f, 0, sizeof(f));
	
	for (int i = 1; i <= n; ++i) {
		int mx = 0;
		// 从i到i-k去枚举前面的数, 得到最大值mx
		for (int j = i; j > max(0, i - k); --j) {
			mx = max(mx, arr[j - 1]);
			// 转移方程
			f[i] = max(f[i], f[j - 1] + mx * (i - j + 1));
		}
	}
	return f[n];
}

int main(){
	vector<int> test = {1,4,1,5,7,3,6,1,9,9,3};
	int k = 4;
	cout<<maxSumAfterPartitioning(test, k);
}
