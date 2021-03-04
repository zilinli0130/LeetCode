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

/* This problem implements the Depth First Search method to find the smallest subtree containing all the deepest nodes.
If the depth of left and right sub tree are the same, the function returns the root and current depth. Otherwiese,
we return the subtree with the larger depth and its subtree.

Time: O(N)
Space: O(N)

*/

class Solution {
public:
    
    struct TreeInfo {
        TreeNode* tree;
        int depth;
    };
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root, 0).tree;
    }
    
    TreeInfo dfs(TreeNode* root, int depth) {
        
        if (!root) {return TreeInfo{nullptr, depth};}
        
        TreeInfo leftTreeData = dfs(root->left, depth + 1);
        TreeInfo rightTreeData = dfs(root->right, depth + 1);
        
        if (leftTreeData.depth > rightTreeData.depth) {
            
                return TreeInfo{leftTreeData.tree, leftTreeData.depth}; 
            
        } else if (leftTreeData.depth < rightTreeData.depth) {
            
                return TreeInfo{rightTreeData.tree, rightTreeData.depth}; 
        }
      return TreeInfo{root, leftTreeData.depth};  
    }
};
