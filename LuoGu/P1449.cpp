#include<bits/stdc++.h>
using namespace std;

stack<int> res;//�����������,����ȡ����,�е�� 
int main(){
	char ch;
	int num=0;
	do{
		ch=getchar();
		int x,y;
		//***�����ֵ�ascii 
		if(ch>='0'&&ch<='9'){
			//***���������,��ȥƫ��
			num=num*10+ch-'0'; 
		}else if(ch=='.'){
			//����.,�����ִ��ȥ 
			res.push(num);
			num=0; 
		}else if(ch!='@'){//ע���ж�@
				x=res.top();
				res.pop();
				y=res.top();
				res.pop();
			if(ch=='+'){
				res.push(x+y);
			}else if(ch=='-'){
				res.push(y-x);//ע�������˳�� 
			}else if(ch=='*'){
				res.push(x*y);
			}else if(ch=='/'){
				res.push(y/x);//ע�������˳�� 
			}
		}else{
			break;
		}
	}while(1);
	
	//���ջ����Ԫ�ؾ��Ǵ� 
	cout<<res.top();
	return 0;
}
