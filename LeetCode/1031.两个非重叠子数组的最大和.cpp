#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
/*
 * 用双指针, 首先firstLen和secondLen在前在后区别不大, 只不过调用两次函数而已, 不妨只设一边
 * 
 * 设置变量:
 * suml: 左边的数组的和
 * sumr: 右边的数组的和
 * maxl: 左边的最大和
 * 
 * 例如:
 * 0,6,5,2,2,5,1,9,4 f = 1, s = 2;
 * 一开始:
 * suml = 0, maxl = 0
 * sumr = 6 + 5 = 11, res = 11
 * 然后指针往前移动, 左边的数组加入了6, 即0 6, 只需要重新计算一次即可(因为除去6的已经计算出来了):
 * suml = - 0 + 6 = 6, maxl = 6
 * sumr = 11 - 6 + 2 = 7, res = 13
 * 以此类推
 * 
 * 优化:这里面需要循环两次, 直接把它写到一次循环里面
 */
int half(vector<int>& nums, int firstLen, int secondLen) {
	int suml = accumulate(nums.begin(),nums.begin()+firstLen,0);
	int maxl = suml;
	int sumr = accumulate(nums.begin()+firstLen, nums.begin()+firstLen+secondLen,0);
	int res = maxl + sumr;
	for(int i = firstLen, j = i + secondLen, z = i - firstLen;j<nums.size();i++,j++, z++){
		sumr += nums[i+secondLen] - nums[i];
		suml += nums[i] - nums[z];
		maxl = max(suml, maxl);
		res = max(res, maxl+sumr);
	}
	return res;
}

int _maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
	int l = half(nums,firstLen,secondLen);
	int r = half(nums,secondLen,firstLen);
	return max(l,r);
	//return max(half(nums,firstLen,secondLen), half(nums,secondLen,firstLen));
}
// 一次循环版本
int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
	int suml1 = accumulate(nums.begin(),nums.begin()+firstLen,0);
	int maxl1 = suml1;
	int sumr1 = accumulate(nums.begin()+firstLen, nums.begin()+firstLen+secondLen,0);
	int res1 = maxl1 + sumr1;
	
	int suml2 = accumulate(nums.begin(),nums.begin()+secondLen,0);
	int maxl2 = suml2;
	int sumr2 = accumulate(nums.begin()+secondLen, nums.begin()+firstLen+secondLen,0);
	int res2 = maxl2 + sumr2;
	for(int i1 = firstLen, j1 = i1 + secondLen, z1 = i1 - firstLen,
			i2 = secondLen,j2 = i2 + firstLen , z2 = i2 - secondLen,
		    flag1 = 1, flag2 = 1
		    ;flag1 || flag2;){
		if(j1 >= nums.size()) flag1 = 0;
		if(j2 >= nums.size()) flag2 = 0;
		// f s
		if(flag1){
			sumr1 += nums[i1+secondLen] - nums[i1];
			suml1 += nums[i1] - nums[z1];
			maxl1 = max(suml1, maxl1);
			res1 = max(res1, maxl1+sumr1);
			i1++,j1++,z1++;
		}
		// s f
		if(flag2){
			sumr2 += nums[i2+firstLen] - nums[i2];
			suml2 += nums[i2] - nums[z2];
			maxl2 = max(suml2, maxl2);
			res2 = max(res2, maxl2+sumr2);
			i2++,j2++,z2++;
			
		}
	}
	return max(res1,res2);
}

int main(){
	vector<int> test = {3,7,15,4,15,5,20,14,16,16,10,5,14,7,12,10};
	int f = 7;
	int s = 9;
	//cout<<_maxSumTwoNoOverlap(test, f, s)<<endl;
	cout<<maxSumTwoNoOverlap(test,f,s);
}
	



