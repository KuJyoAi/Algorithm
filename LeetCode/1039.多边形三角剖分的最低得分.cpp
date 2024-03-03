#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int dp[51][51];

int dfs(vector<int> &v,int i, int j){
	if(dp[i][j]!=0){
		return dp[i][j];
	}else if(j<i+2){
		return 0;
	}else if(j==i+2){
		dp[i][j]=v[i]*v[i+1]*v[i+2];
		return dp[i][j];
	}
	
	dp[i][j]=0x7fffff;
	for(int k=i+1;k<j;k++){
		dp[i][j]=min(dp[i][j],dfs(v,i,k)+dfs(v,k,j)+v[i]*v[k]*v[j]);
	}
	return dp[i][j];
}
int minScoreTriangulation(vector<int>& values) {
	int n = values.size();
	
	dfs(values,0,n-1);
	return dp[0][n-1];
}
int main(){
	vector<int> v={1,3,1,4,1,5};
	auto res = minScoreTriangulation(v);
	cout<<res;
}
