#include<bits/stdc++.h>
using namespace std;

stack<int> res;//本题在洛谷上,答案是取整的,有点坑 
int main(){
	char ch;
	int num=0;
	do{
		ch=getchar();
		int x,y;
		//***是数字的ascii 
		if(ch>='0'&&ch<='9'){
			//***这里很巧妙,减去偏移
			num=num*10+ch-'0'; 
		}else if(ch=='.'){
			//读到.,把数字存进去 
			res.push(num);
			num=0; 
		}else if(ch!='@'){//注意判断@
				x=res.top();
				res.pop();
				y=res.top();
				res.pop();
			if(ch=='+'){
				res.push(x+y);
			}else if(ch=='-'){
				res.push(y-x);//注意操作符顺序 
			}else if(ch=='*'){
				res.push(x*y);
			}else if(ch=='/'){
				res.push(y/x);//注意操作符顺序 
			}
		}else{
			break;
		}
	}while(1);
	
	//最后栈顶的元素就是答案 
	cout<<res.top();
	return 0;
}
