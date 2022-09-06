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
    TreeNode* build(vector<int> &arr, int &i, int ub)
    {
        if(i == arr.size() || arr[i] > ub)
           return NULL;
        
        TreeNode *root = new TreeNode(arr[i++]);
        
        root->left = build(arr, i, root->val);
        root->right = build(arr, i, ub);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int i = 0;
        
        return build(preorder, i, INT_MAX); // INT_MAX will be my initial upper bound
    }
};