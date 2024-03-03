#include<iostream>

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x*f;
}

//inline void write(int x)
//{
//	if(x<0)
//		putchar('-'),x=-x;
//	if(x>9)
//		write(x/10);
//	putchar(x%10+'0');
//	return;
//}
// 栈优化版
void write(int x) {
	static int sta[35];
	int top = 0;
	do {
		sta[top++] = x % 10, x /= 10;
	} while (x);
	while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}


int main(){
	// 输入输出解绑, 注意不能同时使用cout和printf等
	// std::ios::sync_with_stdio(false)
	int a = read();
	
	write(a);
}
