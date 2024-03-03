#include<iostream>
#include<vector>

using namespace std;
// 在矩阵上写出字母 Y 所需的最少操作次数
int minimumOperationsToWriteY(vector<vector<int>>& grid) {
    // 统计Y和非Y的元素个数
    vector<int> Y(3, 0); // 0, 1, 2
    vector<int> nY(3, 0); // 0, 1, 2
    int n = grid.size();
    // Y的中心点
    int center = n / 2;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if (i < center){
                if (i == j || i + j == n - 1){
                    Y[grid[i][j]]++;
                }else{
                    nY[grid[i][j]]++;
                }
            }else{
                if(j==center){
                    Y[grid[i][j]]++;
                }else{
                    nY[grid[i][j]]++;
                }
            }
        }
    }

    int res = 0x3f3f3f3f;
    // Y == 0:
    res = min(res, Y[1] + Y[2] + min(nY[0] + nY[1], nY[0] + nY[2]));

    // Y == 1:
    res = min(res, Y[0] + Y[2] + min(nY[1] + nY[0], nY[1] + nY[2]));

    // Y == 2:
    res = min(res, Y[0] + Y[1] + min(nY[2] + nY[0], nY[2] + nY[1]));
    return res;
}

int main(){
    // grid = [[1,2,2],[1,1,0],[0,1,0]]
    // 3
    vector<vector<int>> grid = {{1,2,2},{1,1,0},{0,1,0}};
    cout << minimumOperationsToWriteY(grid) << endl;
    return 0;
}