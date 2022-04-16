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
For building a Greater BST from the original BST, we need to process right subtree before passing the cumulative sum to left subtree.
To ensure we process nodes in decreasing order of their values, we would use an inorder traversal. But instead of using the traditional Left->Vertex->Right , we would use the Right->Vertex->Left.
Once we are clear on the traversal method, the rest is easy and we just need an accumulator variable to pass the cumulative sum from right subtree to the left one.
*/

class Solution {
public:
    int sum = 0;
    
    TreeNode* convertBST(TreeNode* root) 
    {
        if(root == NULL)
            return root;
        
        convertBST(root->right); // Go to extreme right
        
        sum += root->val;
        root->val = sum;
        
        convertBST(root->left); 
        
        return root;        
    }
};