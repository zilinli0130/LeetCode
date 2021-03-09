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

/*
This problem impements the Dpeth First Search method to traverse the entire BTS until we reach one level on top of
the desired depth. We then create two new TreeNode() pointers to recreate that portion of BST

Time : O(N)
Space : O(D)
where N is the total number of nodes inside the BST and D is the depth of BST
*/
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        
        if (d == 1) {
            TreeNode* newTree = new TreeNode(v);
            newTree->left = root;
            return newTree;
        }
        dfs(root, v, 1, d);
        return root;
        
    }
    
    void dfs(TreeNode* root, int v, int depth, int d) {
        
        if (depth == d - 1) {
            if (root != nullptr) {
                TreeNode *newLeftTree = new TreeNode(v);
                TreeNode *newRightTree = new TreeNode(v);
                newLeftTree->left = root->left;
                newRightTree->right = root->right;
                root->left = newLeftTree;
                root->right = newRightTree;
                return;
            } 
            
        } else if (depth < d - 1) {
            if (root->left != nullptr) { dfs(root->left, v, depth + 1, d);}
            if (root->right != nullptr) { dfs(root->right, v, depth + 1, d);}
        } 
    }
};