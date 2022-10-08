// Problem - https://leetcode.com/problems/path-sum/


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
  bool solve(TreeNode* root, int sum, int cnt)
  {
    if(root == NULL) return false;
    
    // leaf node
    if(root->left == NULL && root->right == NULL)
        return (sum == cnt + root->val);
    
    bool x = false;
    
    if(root->left)
        x |= solve(root->left, sum, cnt + root->val);

    if(root->right)
        x |= solve(root->right, sum, cnt + root->val);
    
    return x;
  }
  
  bool hasPathSum(TreeNode* root, int sum) {
    return solve(root, sum, 0);
  }
};