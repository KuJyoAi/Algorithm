#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

/*
 * 动态规划:
 * 随便取一个单词, 例如说bda, 依次去掉得到:
 * da, ba, bd, 如果说我们已经计算出这三个单词的链长度, 分别加1取最大值即可
 * 
 * 这题的难点在于: 如何存储动态规划的数组, 答案是哈希表
 * 
 * 此外还需要先给单词按长度排序, 递推计算
 */
int longestStrChain(vector<string>& words) {
	unordered_map<string, int> cnt;
	// words排序
	sort(words.begin(), words.end(), [](const string &a, const string &b) {
		return a.size() < b.size();
	});
	
	int res = 0;
	for (string word : words) {
		// 每个单词最小单词链为1
		cnt[word] = 1;
		for (int i = 0; i < word.size(); i++) {
			// 前身
			string prev = word.substr(0, i) + word.substr(i + 1);
			if (cnt.count(prev)) {
				cnt[word] = max(cnt[word], cnt[prev] + 1);
			}
		}
		res = max(res, cnt[word]);
	}
	return res;
}

int main(){
	vector<string> s = {"a","b","ba","bca","bda","bdca"};
	cout<<longestStrChain(s);
}
