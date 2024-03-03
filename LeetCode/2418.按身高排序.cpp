#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
	int n = names.size();
	vector<int> indices(n);
	// iota: 产生连续自增的数值, 这里把indices变成1 2 3 ... n-1
	iota(indices.begin(), indices.end(), 0);
	// 对indices排序, indices就是下标
	// 可以学习这里函数的写法
	sort(indices.begin(), indices.end(), [&](int x, int y) {
		return heights[x] > heights[y];
	});
	
	vector<string> res(n);
	for (int i = 0; i < n; i++) {
		res[i] = names[indices[i]];
	}
	return res;
}

int main(){
	vector<string> names = {"Mary","John","Emma"};
	vector<int> heights = {180,165,170};
	auto res =  sortPeople(names, heights);
	for(auto r:res){
		cout<<r<<" ";
	}
	return 0;
}
