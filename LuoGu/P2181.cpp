#include<iostream>
using namespace std;
int main() {
	long long n;
	cin >> n;
	long long ans1 = n * (n - 1) / 2;
	long long ans2 = ans1 * (n - 2) / 3;
	long long ans3;
	if (ans2%4==0)
	{
		ans3 = ans2 / 4 * (n - 3);
	}
	else if (ans2%2==0)
	{
		ans3 = (ans2 / 2) * ((n - 3)/2);
	}
	else {
		ans3 = ans2  * ((n - 3)/4);
	}
	cout << ans3;
	return 0;
}