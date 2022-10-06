/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/
//problem link
// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
class Solution {
public:
    int findmaxpathsum(TreeNode* root, int &maxi){
        if(root==NULL)
            return 0;
        int leftmaxpath=max(0,findmaxpathsum(root->left,maxi));
        int rightmaxpath=max(0,findmaxpathsum(root->right,maxi));
        int value=root->val;
        maxi=max(maxi,leftmaxpath+rightmaxpath+value);
        return max(leftmaxpath,rightmaxpath)+value;
        
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        findmaxpathsum(root,maxi);
        return maxi;
    }
};
