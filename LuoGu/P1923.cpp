#include<bits/stdc++.h>
using namespace std;
int a[5000001];
int n,k;
/*
˼·:�ڿ��ŵĻ���������
�����һ����׼,��ֳ�������,�����ǽ������ֱַ�����,����ֻ��Ҫ��һ��
����,����˼·Ҳ���ҵ�kС��һ��˼· 
*/ 
void search(int l, int r);
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
	}
	search(0,n-1);
	return 0;
}
void search(int l, int r){
	if(r<=l){
		cout<<a[l];
		return;
	}
	int left=l;//��׼(l)�±� 
	int right=r;
	int pivot=a[l];//��׼;
	int tmp=0;
	while(r!=l){
		while(r>l){
			if(a[r]<pivot){
				break;
			}
			r--;
		}
		
		while(r>l){
			if(a[l]>pivot){
				break;
			}
			l++;
		}
		if(l==r){
			break;
		}
		tmp=a[l];
		a[l]=a[r];
		a[r]=tmp;
	} 
	
	//������׼
	tmp=a[l]; 
	a[l]=pivot;
	a[left]=tmp;
	//�ж�k��λ�� 
	if(l==k){
		cout<<a[l];
		return ;
	}else if(l>k){
		search(left,l-1);
	}else{
		search(l+1,right);
	}
}
