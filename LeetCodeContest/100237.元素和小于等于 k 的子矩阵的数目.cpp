#include<iostream>
#include<vector>
using namespace std;

// 包含左上角的<=k的子矩阵的个数
int countSubmatrices(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> sum(m+1, vector<int>(n+1, 0));
    int res = 0;

    for(int i = 1; i <= m; i++){
        sum[i][0] = sum[i-1][0] + grid[i-1][0];
    }

    for(int j = 1; j <= n; j++){
        sum[0][j] = sum[0][j-1] + grid[0][j-1];
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i-1][j-1];
        }

        if (sum[i][0] <= k){
            res++;
        }
    }  

    return res;
}
int main(){
    vector<vector<int>> grid = {{7,6,3},{6,6,1}};
    int k = 18;
    cout << countSubmatrices(grid, k) << endl;
    return 0;
}