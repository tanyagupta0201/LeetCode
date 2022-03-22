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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root == NULL)
            return false;
        
        int value = root->val;
        
        if(root->left == NULL && root->right == NULL)
            return (targetSum - value) == 0;
        
        return hasPathSum(root->left, targetSum - value) || hasPathSum(root->right, targetSum - value);
        
    }
};