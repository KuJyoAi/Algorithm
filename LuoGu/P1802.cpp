#include<iostream>
#include<algorithm>
using namespace std;
struct exp {
	long long lose;
	long long win;
	int x;
};
int n;
int x;
struct exp res[1001];
long long beat(int i, int j);
long long solve(int i, int j);
long long dp[1001][1001];
//用j瓶药水打第i(+1)个人
long long beat(int i, int j) {
		if (j >= res[i].x)
		{
			return res[i].win;
		}
		else {
			return res[i].lose;
		}
}
long long solve(int i, int j) {
	if (i==0)
	{
		
		dp[0][j] = beat(0, j);
		return dp[0][j];
	}

	if (dp[i][j]!=0)
	{
		return dp[i][j];
	}

	long long score=0,tmp;
	for (int k = 0; k <= res[i].x && k <= j; k++)
	{
		//cout << "\ti:" << i << "\tj:" << j << "\tdp:" << dp[i][j] << endl;
		tmp = solve(i - 1, j - k) + beat(i, k);
		if (tmp>score)
		{
			score = tmp;
		}
	}
	
	dp[i][j] = score;
	return score;
}
int main() {
	cin >> n >> x;
	
	for (int i = 0; i < n; i++)
	{
		cin >> res[i].lose >> res[i].win >> res[i].x;
		//cout << res[i].lose << res[i].win << res[i].x<<endl;
	}
	
	solve(n, x);
	cout << dp[n][x]*5;
}