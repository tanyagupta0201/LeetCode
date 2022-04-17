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

// https://leetcode.com/problems/increasing-order-search-tree/discuss/1956583/C%2B%2B-Never-Forget-Again-Brute-Force-greaterStack-greaterRecursion-or-All-Solutions!

class Solution {
  public:

  TreeNode * dummy, * cur;
  void inorder(TreeNode * root)
  {
    if (!root) return;
    inorder(root -> left);

    cur -> right = root;
    root -> left = NULL;

    cur = cur -> right;
    inorder(root -> right);
  }

  TreeNode * increasingBST(TreeNode * root) 
  {
    dummy = cur = new TreeNode();

    inorder(root);
    return dummy -> right;
  }

};