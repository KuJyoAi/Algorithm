#include<iostream>
#include<vector>
using namespace std;
/*
 * 动态规划解决, f[i]表示前i个结果, 难点在于写出转移方程
 * 
 * 实际上往前查找, 并用贪心就可以解决
 * 跟之前的书架一起排列(横着), 如果宽度大于书架宽度就不用排列了, 直接退出
 * 
 * 为什么贪心可以解决呢?
 * 可以思考这种情况:
 * 1 2 3 4
 * 5 2 6 7
 * 
 * 运算到4的时候, 认为排列是1 2 3 4
 * 							  2
 * 
 * 运算到5的时候, 认为排列是2 3 4 5
 * 							2
 * 虽然位置有差, 但是实际上不影响, 因为宽度才是决定性的
 */
int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
	int n = books.size();
	int f[n + 1];
	f[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int w = books[i - 1][0], h = books[i - 1][1];
		f[i] = f[i - 1] + h;
		for (int j = i - 1; j > 0; --j) {
			w += books[j - 1][0];
			if (w > shelfWidth) {
				break;
			}
			h = max(h, books[j - 1][1]);
			f[i] = min(f[i], f[j - 1] + h);
		}
	}
	return f[n];
}

int main(){
	vector<vector<int>> test = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
	int w = 4;
	cout<< minHeightShelves(test, w);
	return 0;
}
