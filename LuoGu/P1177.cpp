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
		//j�ȶ�,��������,
		while (res[j] >= temp && i < j) {
			j--;
		}
		//i��,��������
		while (res[i] <= temp && i < j) {
			i++;
		}
		//�ҵ�i j ,����
		if (i < j)
		{
			t = res[i];
			res[i] = res[j];
			res[j] = t;
		}

	}
	//һ�����,��׼����λ,���ȫС�ڻ�׼,�ұ�ȫ���ڻ�׼
	//��Ϊres[left]=temp,���Բ���Ҫ�ȱ���res[left]��ֵ
	res[left] = res[i];
	res[i] = temp;
	quicksort(left, i - 1);
	quicksort(i + 1, right);
}
