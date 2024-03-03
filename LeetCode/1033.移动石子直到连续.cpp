#include<iostream>
#include<vector>
using namespace std;
/*
 * 最大值的求法很简单, 左右各移动一步, 步数为r-l-2
 * 
 * 最小值:
 * 都连续放置: 0
 * 一个连续放置: 1
 * 有一个间隔放置: 1
 * 其他:
 */
vector<int> numMovesStones(int a, int b, int c) {
	int l = min(a,min(b,c));
	int r = max(a,max(b,c));
	int m = a+b+c-l-r;
	int _min = !(r-m==1&&m-l==1) + (r-m > 2 && m-l > 2);
	return {_min,r-l-2};
}

int main(){
	vector<int> test = {4, 3, 2};
	auto res = numMovesStones(test[0],test[1],test[2]);
	cout<<res[0]<<" "<<res[1];
	return 0;
}
