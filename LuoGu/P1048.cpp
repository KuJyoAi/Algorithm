#include<iostream>
using namespace std;
long long pick(int i,int j);
long long sovle(int i ,int j);
struct curb {
	int val;
	int tim;
};
int T, M;
int mint[102];
struct curb curbs[102];
long long dp[102][1002];
int main() {
	cin >> T >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> curbs[i].tim >> curbs[i].val;
		if (mint[i-1] > curbs[i].tim && i != 0)
		{
			mint[i] = curbs[i].tim;
		}
		else if (i==0)
		{
			mint[i] = curbs[i].tim;
		}
		else {
			mint[i] = mint[i - 1];
		}
	}
	sovle(M, T);
	cout << dp[M][T];
	return 0;
}


long long pick(int i, int j) {
	if (curbs[i].tim <= j)
	{
		return curbs[i].val;
	}
	else {
		return 0;
	}
}

long long sovle(int i, int j) {
	//cout << "i:" << i << "\tj:" << j << "\tdp:" << dp[i][j]<<endl;
	if (i == 0)
	{
		dp[i][j] = pick(i, j);
		return dp[i][j];
	}
	else if (j < mint[i])
	{
		return 0;
	}

	if (dp[i][j] != 0)
	{
		return dp[i][j];
	}

	long long t1 = 0, t2 = curbs[i].tim < j ? curbs[i].tim : j, res1, res2;
	res2 = sovle(i - 1, j - t2) + pick(i, t2);
	res1 = sovle(i - 1, j - t1) + pick(i, t1);
	
	
	dp[i][j] = res1 > res2 ? res1 : res2;
	return dp[i][j];
}

/*
* 本题是标准模板,背包问题变式,但是不简单,直接用背包解决会TLE
* 优化有两处:
* 第一:对t1,t2,实际上只需要取两个值,不需要取中间,因为都收集不了药草
* 第二:j的递减会导致巨大的浪费,故用mint(前i个最小的时间),筛去j<mint[i]的情况,返回0
*/