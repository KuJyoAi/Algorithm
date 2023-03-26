#include<bits/stdc++.h>
using namespace std;
int a[5000001];
int n,k;
/*
思路:在快排的基础上搜索
随便找一个基准,会分出两部分,快排是将两部分分别排序,此题只需要排一边
所以,快排思路也是找第k小的一种思路 
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
	int left=l;//基准(l)下标 
	int right=r;
	int pivot=a[l];//基准;
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
	
	//交换基准
	tmp=a[l]; 
	a[l]=pivot;
	a[left]=tmp;
	//判断k的位置 
	if(l==k){
		cout<<a[l];
		return ;
	}else if(l>k){
		search(left,l-1);
	}else{
		search(l+1,right);
	}
}
