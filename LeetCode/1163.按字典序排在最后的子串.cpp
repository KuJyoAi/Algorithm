#include<iostream>
#include<vector>
using namespace std;
/*
 * 字典序:
 * 无 < a-z
 * 如a < aa
 * 
 * 因此, 保证前面大的情况下, 尽可能越长越好, 从而最长字串一定有最后一个字符
 * 即答案一定是后缀子串
 * 
 * 其次, 最前面的字母权重最大, 所以第一个字母一定是最大的
 * 然后比较第二个字母
 * 
 * 用i记录得到的最大的字母, 用j遍历, i <= j
 * 
 * 分几种情况考虑:
 * 1. s[i] < s[j]: 很显然, 把i记录为j即可
 * 2. s[i] > s[j]: 让j继续前进
 * 3. s[i] = s[j]: 需要比较下一个字符, 用k记录
 * 				   即比较s[i+k]和s[j+k], 再根据情况分三种, 不再赘述
 * 
 * 有几个样例过不去, 为什么?
 * 
 */
string _lastSubstring(string s) {
	int n = s.size();
	int i = 0, j = 1;
	while(j < n){
		if(s[i] < s[j]){
			i = j;
			j++;
		}else if(s[i] == s[j]){
			int k = 1;
			while(j+k<n){
				if(s[i+k]<s[j+k]){
					// 注意是i+k+1不是j+k+1
					i += k + 1;
					if(i>=j){
						j = i + 1;
					}
					break;
				}else if(s[i+k]==s[j+k]){
					k++;
				}else{
					j = j + k + 1;
					break;
				}
			}
			if(j+k==n){
				return s.substr(i);
			}
		}else{
			// s[i] > s[j]
			j++;
		}
	}
	return s.substr(i);
}
/*
 * 另一种思路, O(n)
 * 
 * 核心思路是几个状态转移:
 * 1. 开始时k=0, 如果s[i] = s[j], k++, 即进行下一个字母的比较
 * 
 * 2. 如果s[i+k] < s[j+k], 说明结果不是最优的, 这里的转移很关键
 * x_i x_i+1 x_i+2 ... x_i+k
 * x_j x_j+1 x_j+2 ... x_j+k
 * 
 * i需要取i+k后面那个数, 即i+=k+1
 * 假设i取i+r, 那么j+r开始的子串就比它大(r<k)
 * 这里会造成一种误解: 即以为应该i=j, 实际上, i+k < j时这种转移就是错误的
 * 
 * 比如:(x表示合理的一个数)
 * i:823xxxxx66xx824xxxxxxx
 * j:878xxxxxxxxx
 * i就不能转移到第二个8, 否则会跳过正确答案88xx
 * 
 * 3. 如果s[i+k] > s[j+k], 说明i暂时是最优的, 对j进行转移
 * 一般的想法是j+=1, 但是可以优化:
 * i:828xxxxxx9xx827xxxxxxx
 * j:878xxxxxxxxx
 * 
 */
string lastSubstring(string s) {
	int n = s.size();
	int i = 0;
	for (int j = 1, k = 0; j + k < n;) {
		if (s[i + k] == s[j + k]) {
			++k;
		} else if (s[i + k] < s[j + k]) {
			i += k + 1;
			k = 0;
			if (i >= j) {
				j = i + 1;
			}
		} else {
			j += k + 1;
			k = 0;
		}
	}
	return s.substr(i);
}

int main(){
	string s = "zvyjbgaznzayfwsaumeccpfwamfzmkinezzwobllyxktqeibfoupcpptncggrdqbkji";
	cout<<lastSubstring(s);
	return 0;
}
