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

// Explanation: 
// https://leetcode.com/problems/recover-binary-search-tree/discuss/1962981/Idea-%3A-Inorder-Traversal-oror-Easy-to-understand


class Solution 
{
    TreeNode *first, *last, *prev;
    
public:
    
    void inorder(TreeNode *root)
    {
        if(!root)
            return;
        
        inorder(root -> left);
        
        if(prev != NULL && (root -> val < prev -> val))
        {
            if(first == NULL)
            {
                first = prev;
                last = root;
            }
            else 
                last = root;
        }
        
        prev = root;
        inorder(root -> right);
    }
    
    void recoverTree(TreeNode* root) 
    {
        first = last = prev = NULL;
        inorder(root);
        swap(first -> val, last -> val);
    }
};