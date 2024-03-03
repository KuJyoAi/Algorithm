#include <iostream>
using namespace std;

void PrintfMatrix(unsigned char m[4][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%4x",m[i][j]);
			if(j%4==3)
				puts("");
		}
		
	}
}
unsigned char xtime(unsigned char st)
{
	return (st<<1)^((st&0x80)?0x1b:0x00);     //x乘法   二进制串左移一位，判断最高位是否溢出，溢出要异或0x1b
}
void mixcolumns(unsigned char state[4][4],unsigned char cipher[4][4])
{
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<4;i++)
		{
			cipher[i][j]=xtime(state[i%4][j])      //0x02乘法
			^(state[(i+1)%4][j])^xtime(state[(i+1)%4][j])//0x03乘法
			^state[(i+2)%4][j]      //0x01乘法
			// ^state[(i+2)%4][j];     //0x01乘法   这句写错了，so结果不对，应该是i+3
			^state[(i+3)%4][j];     //0x01乘法
		}
	}
}
int main()
{
	unsigned char state[4][4]={
		/*0,4,8,12,
		  1,5,9,13,
		  2,6,10,14,
		  3,7,11,15,*/
		/*0x87,0xF2,0x4D,0x97,
		0x6E,0x4C,0x90,0xEC,
		0x46,0xE7,0x4A,0xC3,
		0xA6,0x8C,0xD8,0x95,
		  */
		0x12,0xF2,0x4D,0x97,
		0x34,0x4C,0x90,0xEC,
		0x56,0xE7,0x4A,0xC3,
		0x78,0x8C,0xD8,0x95,
	};
	unsigned char cipher[4][4]; 
	printf("明文为:\n");PrintfMatrix(state);
	mixcolumns(state,cipher);
	printf("列混合结果:\n");PrintfMatrix(cipher);
	return 0;
}
