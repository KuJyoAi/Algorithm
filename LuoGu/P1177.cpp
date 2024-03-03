#include<bits/stdc++.h>
using namespace std;
void quicksort(int left,int right);
int res[100000];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>res[i];
    }
    quicksort(0,n-1);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    
}


void quicksort(int left, int right) {
	int i, j, t, temp;
	if (left > right)
	{
		return;
	}

	temp = res[left];
	i = left;
	j = right;
	while (i != j) {
		//j先动,从右往左,
		while (res[j] >= temp && i < j) {
			j--;
		}
		//i后动,从左往右
		while (res[i] <= temp && i < j) {
			i++;
		}
		//找到i j ,交换
		if (i < j)
		{
			t = res[i];
			res[i] = res[j];
			res[j] = t;
		}

	}
	//一轮完成,基准数归位,左边全小于基准,右边全大于基准
	//因为res[left]=temp,所以不需要先保存res[left]的值
	res[left] = res[i];
	res[i] = temp;
	quicksort(left, i - 1);
	quicksort(i + 1, right);
}
