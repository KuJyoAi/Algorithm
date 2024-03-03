#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<char, vector<char>> m;
string dig;
void dfs(vector<string> &ans, string now, size_t pos){
	if(pos>=dig.size()){
		// 完毕
		if(now.size()==0){
			return;
		}
		ans.push_back(now);
		return ;
	}
	
	const vector<char> &nxt = m[dig[pos]];
	
	for(auto a:nxt){
		dfs(ans, now+a, pos+1);
	}
}

vector<string> letterCombinations(string digits) {
	m['2'] = {'a','b','c'};
	m['3'] = {'d','e','f'};
	m['4'] = {'g','h','i'};
	m['5'] = {'j','k','l'};
	m['6'] = {'m','n','o'};
	m['7'] = {'p','q','r','s'};
	m['8'] = {'t','u','v'};
	m['9'] = {'w','x','y','z'};
	vector<string> ans;
	dig = digits;
	dfs(ans, "", 0);
	return ans;
}


int main(){
	
	auto v = letterCombinations("23");
	for(int i=0;i<=v.size();i++){
		cout<<v[i]<<" ";
	}
}
