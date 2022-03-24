/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // The point where the node splits is the LCA
    // One node to the left and one to the right
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == NULL)
            return NULL;
        
        int curr = root->val;
        
        if(curr < p->val && curr < q->val)
            return lowestCommonAncestor(root->right, p, q);
        
        if(curr > p->val && curr > q->val)
            return lowestCommonAncestor(root->left, p, q);
        
        return root;        
    }
};