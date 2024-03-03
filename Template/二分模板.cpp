#include<iostream>
#include<vector>
using namespace std;

// 精确找target
int bi_search(vector<int> v, int target){
	int l = 0, r = v.size() - 1;
	while(l <= r){
		int m = (l+r)>>1;
		if(v[m]==target){
			return m;
		}else if (v[m] > target){
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
	int l = 0, r = nums.size() - 1;
	int start = -1, end = -1;
	while(l <= r){
		int m = (l+r)>>1;
		if(nums[m]==target){
			start = m;
			r = m - 1; // 关键: 要找到target的第一个字符, 则相当于把右界不断往左偏移
		}else if (nums[m] > target){
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	
	l = 0;
	r = nums.size() - 1;
	while(l <= r){
		int m = (l+r)>>1;
		if(nums[m]==target){
			end = m;
			l = m + 1; // 关键: 要找到target的最后一个字符, 则相当于把左界不断往右偏移
		}else if (nums[m] > target){
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	
	return {start, end};
}
