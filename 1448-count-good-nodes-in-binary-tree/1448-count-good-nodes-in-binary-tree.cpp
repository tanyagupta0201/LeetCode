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
    void CountNodes(TreeNode* root, int &cnt, int maxValue)
    {
        if(root == NULL)
            return;
       
        if(root->val >= maxValue)
        {
            cnt++;
            maxValue = root->val;
        }
        
        CountNodes(root->left, cnt, maxValue);
        CountNodes(root->right, cnt, maxValue);        
        
    }
    
    int goodNodes(TreeNode* root) 
    {        
        int cnt = 0;
        
        if(root == NULL)
            return 0;
             
        CountNodes(root, cnt, root->val);       
        
        return cnt;        
    }
};