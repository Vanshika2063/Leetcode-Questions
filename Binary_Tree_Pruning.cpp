// https://leetcode.com/problems/binary-tree-pruning/
class Solution {
public:
    bool ans(TreeNode* root){
        if(root==NULL){
            return false;
        }
        bool one=ans(root->left);
        bool two=ans(root->right);
        if(one==false){
            root->left=NULL;
        }
        if(two==false){
            root->right=NULL;
        }
        return root->val||one||two;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool keep=ans(root);
        if(keep==false){
            return NULL;
        }
        return root;
    }
};
