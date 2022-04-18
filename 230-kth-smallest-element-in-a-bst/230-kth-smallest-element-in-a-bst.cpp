// https://leetcode.com/problems/kth-smallest-element-in-a-bst/discuss/1960046/Multiple-C%2B%2B-solutions-with-explanations-and-time-complexity!

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
    vector<int> a;
    
    int kthSmallest(TreeNode* root, int k) 
    {
        inorder(root);
        int ans = a[k-1];
        return ans;
    }
    
    void inorder(TreeNode* root)
    {
        if(!root) 
            return;
        
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
};