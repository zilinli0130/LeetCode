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

/*The problem implements the depth first search. For any given nodes, its value has to be 
strictly less than a max value and greater than a min value, otherwise it's not a valid
node for a binary search tree. The min and max values have to be updated along all the 
future recursion calls. If we traverse to the left, max value has to be updated to the next
node's parent node; If we traverse to the right, min value has to be updated to the next
node's parent node as well.

Time:  O(N)
Space: O(N)
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, INT_MIN - 1, INT_MAX + 1);
    }
    
    bool isValidBSTHelper(TreeNode* root, int minValue, int maxValue) {
        
        if (root == NULL) {
            return true;
        }
        if (root->val <= minValue || root->val >= maxValue) {
            return false;
        }
        bool leftBool = isValidBSTHelper(root->left, minValue, root->val);
        bool rightBool = isValidBSTHelper(root->right, root->val, maxValue);
        return leftBool && rightBool;
    }
};
