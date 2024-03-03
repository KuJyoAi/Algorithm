#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool findSubarrays(vector<int>& nums) {
	unordered_map<int, int> m;
	int n = nums.size();
	for(int i=0;i<n-1;i++){
		int tmp = nums[i]+nums[i+1];
		m[tmp]++;
		if(m[tmp]>=2){
			return true;
		}
	}
	return false;
}

int main(){
	vector<int> v = {1,2,3,4,5};
	findSubarrays(v);
	
	getchar();
}
