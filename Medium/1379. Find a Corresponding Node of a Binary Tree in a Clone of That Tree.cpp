//The main idea is to use depth first search to traverse both tree at the same time
//If the original tree is equal to the target, then we can assign the result to cloned tree

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* result;
        getTargetCopyHelper(original, cloned, target, result);
        return result;
    }
    
    void getTargetCopyHelper(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* &result) {
        
        if (original == NULL) {
            return;
        }
        
        if (original == target) {
            result = cloned;
        }
        
        getTargetCopyHelper(original->left, cloned->left, target, result);
        getTargetCopyHelper(original->right, cloned->right, target, result);
    }
    
};