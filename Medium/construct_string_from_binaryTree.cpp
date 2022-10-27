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
    TreeNode* build(vector<int>& arr, int &i , int bound){
        
        if(i >= arr.size() || arr[i] > bound){
            return NULL;
        }
        
        int ele = arr[i];
        TreeNode* root = new TreeNode(arr[i++]);
        root -> left = build(arr , i , ele);
        root -> right = build(arr , i , bound);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i , INT_MAX);
    }
};