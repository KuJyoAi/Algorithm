#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
	vector<int> preorder;
	vector<int> inorder;
	// 辅助函数, 为了避免频繁修改vector, 只传入下标修改
	TreeNode* helpBuildTree(int pl, int pr, int il, int ir){
		cout<<pl<<" "<<pr<<" "<<il<<" "<<ir<<" "<<endl;
		if(pl == pr){
			return nullptr;
		}
		auto root = new TreeNode(preorder[pl]);
		if(pr - pl == 1){
			return root;
		}
		for(int i=il;i<ir;i++){
			if(inorder[i] == root->val){
				// 以此区分左右子树:
				// preorder: 根 左 右
				// inorder: 左 根 右
				//             i
				int left_len = i - il;
				root->left = helpBuildTree(
					pl+1, pl+left_len+1,
					il, i);
				root->right = helpBuildTree(
					pl+left_len+1,pr, 
					i+1, ir);
				break;
			}
		}
		return root;
	}
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if(preorder.size()==0){
			return nullptr;
		}
		this->preorder = preorder;
		this->inorder = inorder;
		return helpBuildTree(0, preorder.size(), 0, inorder.size());
	}
};

int main(){
	// [3,9,20,15,7]\n[9,3,15,20,7]\n
	
	vector<int> p = {1,2};
	vector<int> i = {2,1};
	Solution* sl = new Solution();
	sl->buildTree(p, i);
}
