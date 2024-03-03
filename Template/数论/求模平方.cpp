#include<iostream>
#include<vector>
using namespace std;
// 欧拉函数
unsigned long long euler(unsigned long long n)
{
	unsigned long long ans = n;
	for (unsigned long long i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ans = ans / i * (i - 1);
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1)
		ans = ans / n * (n - 1);
	return ans;
}

// 模平方算法
unsigned long long modPow(unsigned long long a, unsigned long long b, unsigned long long c)
{
	unsigned long long ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}
	return ans;
}

unsigned long long solve(vector<int> &a, unsigned long long p, int pos)
{
	if (pos == a.size() - 1){
		return a[pos] % p;
	}else {
		auto phi = euler(p);
		auto exp = solve(a, phi, pos + 1) + phi;
		auto ad = a[pos];
		return modPow(ad, exp, p);
	}
}
/*
 * 输入: n p a1 a2 ... an
 * 输出: a1^a2^a3...^an mod p
 */
vector<int> a;
int main()
{
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	
	cout << solve(a, p, 0) << endl;
}
