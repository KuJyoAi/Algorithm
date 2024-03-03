#include<iostream>
#include<vector>
using namespace std;
void heapify(vector<int> &arr, int l, int r);
void HeapSort(vector<int> &arr);
void InitHeap(vector<int> &arr);

int main(){
	vector<int> test = {2, 7, 26, 25, 19, 17, 1, 90, 3, 36};
	HeapSort(test);
	for(auto i:test){
		cout<<i<<" ";
	}
}

void heapify(vector<int> &arr, int root, int end){
	// 左子树和右子树
	int l = root * 2 + 1;
	int r = root * 2 + 2;
	
	while(l <= r){
		int max_root = root;
		if (arr[l] > arr[max_root]){
			max_root = l;
		}
		
		if(r <= end && arr[r] > arr[max_root]){
			max_root = r;
		}
		
		if (max_root == root){
			break;
		}
		
		swap(arr[root],arr[max_root]);
		
		root = max_root;
		l = root * 2 + 1;
		r = l + 1;
	}
}

void HeapSort(vector<int> &arr){
	// 初始化大顶堆
	InitHeap(arr);
	
	int n = arr.size();
	for(int i=0;i<n;i++){
		// 交换第一个元素(最大)和最后一个元素
		swap(arr[0],arr[n- i - 1]);
		// 调整堆
		heapify(arr, 0, n - i - 2);
	}
}

void InitHeap(vector<int> &arr){
	int n = arr.size();
	for(int i=(n-2)/2;i>=0;i--){
		heapify(arr, i, n-1);
	}
}

