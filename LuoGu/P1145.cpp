#include<bits/stdc++.h>
using namespace std;
//��¼˼·:
/*
��������,��k=1;������Ϊ000111 00011 0001
��ÿһ��������Ϊ��ʼ��, ������һ�ε�λ�������һ�ε�ƫ��,ȡģȥ��ѭ��
Ȼ���Ƿ�����[k+1,2k-d]�ڼ��� 
*/
int main(){
	int k=0;;
	cin>>k;
	//�ƶ�ƫ�� 
	int bias=2*k+1;
	//�Ϸ�ƫ��:���ƫ�ƺ�Ϊk+1,�Ҳ�Ϊ2k-d 
	bool is=true;
	for(int m=k+1;true;m++){
		for(int p=0;p<k;p++){
			bias=(m-(2*k-p-bias+1))%(2*k-p);
			bias=bias==0?2*k-p:bias;
			
			if(!(bias>=k+1&&bias<=2*k-p)){
				is=false;
				break;
			}
		}
		if(is){
			cout<<m;	
			return 0;
		}else{
			is=true;
			bias=2*k+1;
		}
	}
	return 0;
}
