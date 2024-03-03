#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool isPossibleToSplit(vector<int>& nums) {
	unordered_map<int, int> m;
	for(auto n:nums){
		m[n]++;
		if(m[n] > 2){
			return false;
		}
	}
	return true;
}
