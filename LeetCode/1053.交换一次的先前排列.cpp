#include<vector>
#include<iostream>
using namespace std;
/*
 * 思路：考虑 1,9,4,6,7
 * 假设左数已经确定，满足条件的右数需要：
 * 1. 小于左数，否则会得到更大的数
 * 2. 越大越好（与左数尽可能接近），这样就能构造出最大的数
 * 
 * 假设右数已经确定，满足条件的左数需要：
 * 1. 大于右数，否则得到更大的数
 * 2. 尽可能在右边，因为右数小于左数，右边权重小
 * 	  所以左数越靠右得到的数越大
 * 
 * 此外，如何判断存在性？
 * 从上面的分析不难得到，需要左数小于右数，因此需要下降段
 * 那么可以总结为：
 * 1. 从右往左找到第一个下降段的数l
 * 2. 从l开始往右找最大的，但不大于l的数r
 * 3. 交换l，r就是结果
 */

vector<int> prevPermOpt1(vector<int>& arr) {
	int l;
	// 从右往左找到第一个降序的元素
	for(int i=arr.size()-2;i>=0;i--){
		if(arr[i]>arr[i+1]){
			l=i;
			break;
		}
	}
	// 没有找到
	if (l==-1){
		return arr;
	}
	// 在l的右边找第一个跟arr[l]最接近但小于l的数
	int r=l+1;
	for(int i=l+2;i<arr.size();i++){
		if(arr[i]<arr[l] && arr[l]-arr[i]<arr[l]-arr[r]){
			r=i;
		}
	}
	swap(arr[l],arr[r]);
	return arr;
}

int main(){
	vector<int> v = {1,9,4,6,7};
	prevPermOpt1(v);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}
