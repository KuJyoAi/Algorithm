#include<iostream>
using namespace std;
int k = 1;
int x, y;
//int board[11][11];
void Sovle2(int Left, int Right, int px, int py) {
	if (px == py && px == Left)
	{
		//左上角
		cout << Right << " " << Right << " " << 1 <<endl;
	}
	else if (px==py && px == Right)
	{
		//右下角
		cout << Left << " " << Left << " " << 4 << endl;
	}
	else if (px = py + 1 && px == Right)
	{
		//右上角
		cout << Left << " " << Right << " " << 2 << endl;
	}
	else
	{
		cout << Right << " " << Left << " " << 3 << endl;
	}
}
void Center(int l, int r, int px, int py) {
	//只剩两格
	if (r - l == 1)
	{
		Sovle2(l, r, px, py);
		return;
	}

	int bound = (r - l + 1) / 2;
	cout << bound;
	if (px > bound && py > bound)
	{
		cout << bound << " " << bound << " " << 4 << endl;
	}
	else if (px <= bound && py > bound)
	{
		cout << bound+1 << " " << bound << " " << 3 << endl;
	}
	else if (px > bound && py <= bound)
	{
		cout << bound << " " << bound+1 << " " << 2 << endl;
	}
	else {
		cout << bound + 1 << " " << bound+1 << " " << 1 << endl;
	}
}
void Sovle(int l, int r, int px, int py,int mid) {
	//只剩两格
	if (r - l == 1)
	{
		Sovle2(l,r, px, py);
		return;
	}
	//分割
	int m = (r - l + 1) / 2;
	if (mid == 1)
	{
		Center(l, m, px, py);
		Center(m + 1, r, m + 1, m+1);
		Center()
	}
}
int main() {
	cin >> k >> x >> y;
	int n = pow(2, k);
	Center(1, n, x, y);
	Sovle(1, n, x, y);
	return 0;
}