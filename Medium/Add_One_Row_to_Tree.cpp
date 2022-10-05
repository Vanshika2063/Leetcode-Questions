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
  
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            depth--;
            if(depth==1){
                for(int i=0;i<sz;i++){
                    auto it=q.front();q.pop();
                    TreeNode* l=new TreeNode(val);
                    TreeNode* r=new TreeNode(val);
                    l->left=it->left;
                    r->right=it->right;
                    it->left=l;
                    it->right=r;
                }
                return root;
            }
            for(int i=0;i<sz;i++){
                auto it=q.front();q.pop();
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
        }
        return NULL;
    }
};
