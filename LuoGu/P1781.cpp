#include<bits/stdc++.h>
using namespace std;
int main(){
	string max;
	string tmp;
	int maxL=0;
	int maxN=0;
	int l=0;
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		l=tmp.length();
		
		//�ȱȽ��ַ������� 
		if(l>maxL){
			maxN=i+1;
			maxL=tmp.length();
			max=tmp;
		}else if(l==maxL){
			//�������,�Ƚ���ֵ 
			int a1=0,a2=0;
			for(int p=0;p<l;p++){
				a1=max[p]-'0';
				a2=tmp[p]-'0';
				//cout<<a1<<" "<<a2;
				if(a2>a1){
					//����������ִ� 
					maxN=i+1;
					maxL=tmp.length();
					max=tmp;
				}else if(a1==a2){
					//��ȼ����Ƚ� 
					continue;
				}else{
					//С,������ 
					break;
				}
			}
		}
	}
	
	cout<<maxN<<endl;
	cout<<max;
	return 0;
}
