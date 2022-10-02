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
    bool isSymmetric(TreeNode* root) { 
        return (root==NULL)||(syshelp(root->left,root->right));
        
    } 
  bool syshelp(TreeNode* lef,TreeNode* rig)
 { 
  if(lef==NULL || rig==NULL)
      return lef==rig; 
  if(lef->val!=rig->val) return false; 
      
   return ((syshelp(lef->left,rig->right))&&(syshelp(lef->right,rig->left)));
     
 }
  
};
