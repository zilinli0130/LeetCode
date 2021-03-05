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
This problem implements the Breadth First Search method by using queue 
to keep track of all the nodes on the same depth level.

Time : O(N)
Space : O(N)
where N is the total number of nodes in the binary tree
*/
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> results;
        queue<TreeNode*> queue; queue.push(root);
        
        while (!queue.empty()) {
            
            double levelSum = 0; int idx = 0, size = queue.size();
            while (idx != size) {
                TreeNode *node = queue.front();
                levelSum += node->val;
                queue.pop();
                if (node->left != NULL) {queue.push(node->left);}
                if (node->right != NULL) {queue.push(node->right);}
                idx++;
            }
            results.push_back((double)levelSum / size);
        }
        return results;
    }
};