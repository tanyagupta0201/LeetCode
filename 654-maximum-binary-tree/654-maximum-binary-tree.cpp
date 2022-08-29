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
    // returns the index of the curr largest element of the array
    int getMaxValue(vector<int> &nums, int l, int r)
    {
        int n = nums.size();
        int idx = 0;
        int maxi = INT_MIN;
        
        for(int i = l; i <= r; i++)
        {
            if(nums[i] > maxi)
            {
                maxi = nums[i];
                idx = i;
            }
        }
        
        return idx;
    }
    
    TreeNode* constructTree(vector<int> &nums, int l, int r)
    {
        if(l > r)
            return NULL;
        
        int i = getMaxValue(nums, l, r); // we get the the index of the max value of the array
        
        TreeNode* newNode = new TreeNode(nums[i]);
        
        newNode->left = constructTree(nums, l, i - 1);
        newNode->right = constructTree(nums, i + 1, r);
        
        return newNode;        
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if(nums.size() == 0)
            return NULL;
        
        return constructTree(nums, 0, nums.size() - 1);
    }
};