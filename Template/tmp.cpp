#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 2e9;
int a[5005]; 

int solve(int l, int r, int h){
	if(l > r) return 0;
	
	int minn = INF, ind = -1;	// 初始化
	int sum = 0;			// 纪录竖着刷的次数
	for(int i = l; i <= r; i++){
		if(a[i] < minn) minn = a[i], ind = i;	// 找到这个区间中的最小值，为下一次分区做准备 
		if(a[i] > h) sum++;			// 如果这个栅栏的高度大于 h 就可以竖着刷
	}
	
	int num = minn - h;		// 计算横着刷的次数 
	int next_h = minn;
	int res_l = solve(l, ind - 1, next_h);
	int res_r = solve(ind + 1, r, next_h):		// num + res_l + res_r 就是横竖交替刷的次数
	int res = min(sum, res_l + res_r + num);	// 比较是全部竖着刷的次数少还是横竖交互刷的次数少 
	
	return res;
}

int main() {
	
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int res = solve(1, n, 0);
	
	cout << res << endl;
	return 0;
	
}

































































































































































































#include<bits/stdc++.h>
using namespace std;
#define DEFINE_1 1
#define DEFINE_2 2
#define DEFINE_3 3
#define DEFINE_4 4
#define DEFINE_5 5
#define DEFINE_6 6
#define DEFINE_7 7
#define DEFINE_8 8
#define DEFINE_9 9
#define DEFINE_10 10
#define DEFINE_11 11
#define DEFINE_12 12
#define DEFINE_13 13
#define DEFINE_14 14
#define DEFINE_15 15
#define DEFINE_16 16
#define DEFINE_17 17
#define DEFINE_18 18
#define DEFINE_19 19
#define DEFINE_20 20
#define DEFINE_21 21
#define DEFINE_22 22
#define DEFINE_23 23
#define DEFINE_24 24
#define DEFINE_25 25
#define DEFINE_26 26
#define DEFINE_27 27
#define DEFINE_28 28
#define DEFINE_29 29
#define DEFINE_30 30
#define DEFINE_31 31
#define DEFINE_32 32
#define DEFINE_33 33
#define DEFINE_34 34
#define DEFINE_35 35
#define DEFINE_36 36
#define DEFINE_37 37
#define DEFINE_38 38
#define DEFINE_39 39
#define DEFINE_40 40
#define DEFINE_41 41
#define DEFINE_42 42
#define DEFINE_43 43
#define DEFINE_44 44
#define DEFINE_45 45
#define DEFINE_46 46
#define DEFINE_47 47
#define DEFINE_48 48
#define DEFINE_49 49
#define DEFINE_50 50
#define DEFINE_51 51
#define DEFINE_52 52
#define DEFINE_53 53
#define DEFINE_54 54
#define DEFINE_55 55
#define DEFINE_56 56
#define DEFINE_57 57
#define DEFINE_58 58
#define DEFINE_59 59
#define DEFINE_60 60
#define DEFINE_61 61
#define DEFINE_62 62
#define DEFINE_63 63
#define DEFINE_64 64
#define DEFINE_65 65
#define DEFINE_66 66
#define DEFINE_67 67
#define DEFINE_68 68
#define DEFINE_69 69
#define DEFINE_70 70
#define DEFINE_71 71
#define DEFINE_72 72
#define DEFINE_73 73
#define DEFINE_74 74
#define DEFINE_75 75
#define DEFINE_76 76
#define DEFINE_77 77
#define DEFINE_78 78
#define DEFINE_79 79
#define DEFINE_80 80
#define DEFINE_81 81
#define DEFINE_82 82
#define DEFINE_83 83
#define DEFINE_84 84
#define DEFINE_85 85
#define DEFINE_86 86
#define DEFINE_87 87
#define DEFINE_88 88
#define DEFINE_89 89
#define DEFINE_90 90
#define DEFINE_91 91
#define DEFINE_92 92
#define DEFINE_93 93
#define DEFINE_94 94
#define DEFINE_95 95
#define DEFINE_96 96
#define DEFINE_97 97
#define DEFINE_98 98
#define DEFINE_99 99
#define DEFINE_100 100
#define DEFINE_101 101
#define DEFINE_102 102
#define DEFINE_103 103
#define DEFINE_104 104
#define DEFINE_105 105
#define DEFINE_106 106
#define DEFINE_107 107
#define DEFINE_108 108
#define DEFINE_109 109
#define DEFINE_110 110
#define DEFINE_111 111
#define DEFINE_112 112
#define DEFINE_113 113
#define DEFINE_114 114
#define DEFINE_115 115
#define DEFINE_116 116
#define DEFINE_117 117
#define DEFINE_118 118
#define DEFINE_119 119
#define DEFINE_120 120
#define DEFINE_121 121
#define DEFINE_122 122
#define DEFINE_123 123
#define DEFINE_124 124
#define DEFINE_125 125
#define DEFINE_126 126
#define DEFINE_127 127
#define DEFINE_128 128
#define DEFINE_129 129
#define DEFINE_130 130
#define DEFINE_131 131
#define DEFINE_132 132
#define DEFINE_133 133
#define DEFINE_134 134
#define DEFINE_135 135
#define DEFINE_136 136
#define DEFINE_137 137
#define DEFINE_138 138
#define DEFINE_139 139
#define DEFINE_140 140
#define DEFINE_141 141
#define DEFINE_142 142
#define DEFINE_143 143
#define DEFINE_144 144
#define DEFINE_145 145
#define DEFINE_146 146
#define DEFINE_147 147
#define DEFINE_148 148
#define DEFINE_149 149
#define DEFINE_150 150
#define DEFINE_151 151
#define DEFINE_152 152
#define DEFINE_153 153
#define DEFINE_154 154
#define DEFINE_155 155
#define DEFINE_156 156
#define DEFINE_157 157
#define DEFINE_158 158
#define DEFINE_159 159
#define DEFINE_160 160
#define DEFINE_161 161
#define DEFINE_162 162
#define DEFINE_163 163
#define DEFINE_164 164
#define DEFINE_165 165
#define DEFINE_166 166
#define DEFINE_167 167
#define DEFINE_168 168
#define DEFINE_169 169
#define DEFINE_170 170
#define DEFINE_171 171
#define DEFINE_172 172
#define DEFINE_173 173
#define DEFINE_174 174
#define DEFINE_175 175
#define DEFINE_176 176
#define DEFINE_177 177
#define DEFINE_178 178
#define DEFINE_179 179
#define DEFINE_180 180
#define DEFINE_181 181
#define DEFINE_182 182
#define DEFINE_183 183
#define DEFINE_184 184
#define DEFINE_185 185
#define DEFINE_186 186
#define DEFINE_187 187
#define DEFINE_188 188
#define DEFINE_189 189
#define DEFINE_190 190
#define DEFINE_191 191
#define DEFINE_192 192
#define DEFINE_193 193
#define DEFINE_194 194
#define DEFINE_195 195
#define DEFINE_196 196
#define DEFINE_197 197
#define DEFINE_198 198
#define DEFINE_199 199
#define DEFINE_200 200
int RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR(int n){
	int res = 0;
	while(n){
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}

inline int SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs()
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
void TTTTTTTTTTTTTTTTTTTTT(int x) {
	static int sta[35];
	int top = 0;
	do {
		sta[top++] = x % 10, x /= 10;
	} while (x);
	while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}

void PMMMMMMMMMMMMMMMMMMMMMMMMMM(unsigned char m[4][4])
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
unsigned char XTTTTTTTTTTTTTTT(unsigned char st)
{
	return (st<<1)^((st&0x80)?0x1b:0x00);     //x乘法   二进制串左移一位，判断最高位是否溢出，溢出要异或0x1b
}
void xtime(unsigned char state[4][4],unsigned char cipher[4][4])
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

bool isnp[1]; //标记是否为 非素数

// 埃氏筛
void ESSSSSSSSSSSSSSSSSSSSSSSSS(int n){
	for(int i=2;i*i<=n;i++){
		if(!isnp[i]){
			for(int j=i*i;j<=n;j+=i){
				isnp[j] = 1;
			}
		}
	}
}
// ax + by = gcd(a,b), d=gcd(a,b)
long long EXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX(long long a, long long b, long long &x, long long &y){
	if (b == 0){
		x = 1;
		y = 0;
		return a;
	}
	long long d = EXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX(b, a % b, x, y);
	long long t = x;
	x = y;
	y = t - a / b * y;
	return d;
}

// 欧拉函数
unsigned long long EUUUUUUUUUUUUUUUUUUUUUUU(unsigned long long n)
{
	unsigned long long ans = n;
	for (unsigned long long i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ans = ans / i * (i - 1);
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1)
		ans = ans / n * (n - 1);
	return ans;
}

// 模平方算法
unsigned long long MPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP(unsigned long long a, unsigned long long b, unsigned long long c)
{
	unsigned long long ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}
	return ans;
}

