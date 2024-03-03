#include<iostream>
#include<vector>
#include<set>
using namespace std;

// 将元素分配到两个数组中 II
vector<int> resultArray(vector<int>& nums) {
	vector<int> arr1, arr2;
	arr1.push_back(nums[0]);
	arr2.push_back(nums[1]);
	multiset<int> s1, s2;
	s1.insert(nums[0]);
	s2.insert(nums[1]);
	
	for(int i = 2; i < nums.size(); i++){
		int cnt1 = distance(s1.upper_bound(nums[i]), s1.end());
		int cnt2 = distance(s2.upper_bound(nums[i]), s2.end());
		
		if (cnt1 > cnt2) {
			arr1.push_back(nums[i]);
			s1.insert(nums[i]);
		}else if (cnt1 < cnt2){
			arr2.push_back(nums[i]);
			s2.insert(nums[i]);
		}else{
			if (s1.size() <= s2.size()){
				arr1.push_back(nums[i]);
				s1.insert(nums[i]);
			}else{
				arr2.push_back(nums[i]);
				s2.insert(nums[i]);
			}
		}
	}
	
	arr1.insert(arr1.end(), arr2.begin(), arr2.end());
	return arr1;
}
int main(){
	// vector<int> nums = {2, 1, 3, 3};
	// 5,14,3,1,2
	vector<int> nums = {5,14,3,1,2};
	vector<int> res = resultArray(nums);
	for(auto r : res){
		cout << r << " ";
	}
	cout << endl;
	return 0;
}
