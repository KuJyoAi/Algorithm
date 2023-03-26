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
* �����Ǳ�׼ģ��,���������ʽ,���ǲ���,ֱ���ñ��������TLE
* �Ż�������:
* ��һ:��t1,t2,ʵ����ֻ��Ҫȡ����ֵ,����Ҫȡ�м�,��Ϊ���ռ�����ҩ��
* �ڶ�:j�ĵݼ��ᵼ�¾޴���˷�,����mint(ǰi����С��ʱ��),ɸȥj<mint[i]�����,����0
*/