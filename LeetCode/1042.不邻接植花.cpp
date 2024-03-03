#include<iostream>
#include<vector>
using namespace std;
/*
 * 思路:
 * 用贪心法解决, 建图
 * 先随便种一种花, 然后标记邻居不能使用这种花
 * 邻居只需要种不是这种花即可
 * 由于每个花园最多只有3个路径, 有4种花, 所以必然有解
 * 值得一提的是: 表示不同花园用不同的花, 可以用位来存储
 * 例如1001
 *     4321
 * 对应位是对应类型的花, 这样只需要存一个数字9即可
 * 
 */
vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
	// 邻接表建图
	vector<vector<int>> adj(n);
	for(auto p:paths){
		adj[p[0] - 1].emplace_back(p[1]-1);
		adj[p[1] - 1].emplace_back(p[0]-1);
	}
	
	// 表示n号花园用的颜色, 用一个int表示, 1110表示用了234号颜色
	vector<int> color(n);
	vector<int> res(n);
	// 开始填色
	for(int i=0;i<n;i++){
		// 给i号上色, 如果color[i] & cl != 0, 说明这个颜色没被上, 否则左移上色
		int cl = 1;
		int cnt = 0;
		while((cl & color[i]) != 0){
			
			cl  = cl << 1;
			cnt++;
		}
		res[i] = cnt+1;
		
		// 标记周围的花园不能上这个色
		for(auto a : adj[i]){
			color[a] = color[a] | cl;
		}
	}
	return res;
}

int main(){
	int n = 4;
	vector<vector<int>> paths ={{1,2},{3,4}};
	auto res = gardenNoAdj(n, paths);
	for(auto i:res){
		cout<<i<<" ";
	}
}
