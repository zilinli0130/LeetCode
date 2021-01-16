/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*This problem implements Depth First Search to find the height and boolean isBalance in each level
of the binary search tree.

Time : O(N)
Space : O(N)

*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).balance;
    }
    
    struct TreeInfo {
	int height;
	bool balance;
    };
    
    TreeInfo dfs(TreeNode* root) {
        
        if (root == NULL) {
            return TreeInfo{0, true};
        }

        TreeInfo leftTreeData = dfs(root->left);
        TreeInfo rightTreeData = dfs(root->right);
        bool heightBool, totalBool;

        if (abs(leftTreeData.height - rightTreeData.height) <= 1) {
            heightBool = true;
        } else {
            heightBool = false;
        }

        totalBool = heightBool && leftTreeData.balance && rightTreeData.balance;
        return TreeInfo{max(leftTreeData.height, rightTreeData.height) + 1, totalBool};   
    }
};