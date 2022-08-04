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
    string ans = "~"; // works as INT_MAX in strings
    
    void getPath(TreeNode* root, string res)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            ans = min(ans,  res);
        }
        
        if(root->left)
            getPath(root->left, char(root->left->val + 'a') + res);
        
        if(root->right)
            getPath(root->right, char(root->right->val + 'a') + res);
        
    }
    
    string smallestFromLeaf(TreeNode* root) 
    {
        if(root == NULL)
           return "";
        
        string res = "";
        res = char(root->val + 'a') + res;
        
        getPath(root, res);
        
        return ans;
    }
};