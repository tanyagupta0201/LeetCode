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
    // Idea: since, val is last element in b => it will either be root or always be inserted in right subtree
    
    // If the value is greater than the root value, it becomes the new root, and the old root becomes the left child (
    // Otherwise, the value needs to be inserted into the right subtree of the root. So we repeat this procedure recursively for the right subtree and it will become the new root of the subtree 
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) 
    {
        
        if(root == NULL || val > root->val)
        {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        
        // otherwise insert into right
        root->right = insertIntoMaxTree(root->right, val);
        return root;        
    }
};