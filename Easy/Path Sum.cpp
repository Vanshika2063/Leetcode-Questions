class Solution {
public:
  
   bool hasPathSum1(TreeNode* root,int targetSum,TreeNode* d){
      if(root==NULL){
      //Condition for leaf node
            if(targetSum==0&&d->left==NULL&&d->right==NULL)return true;
            else return false;
        }
       targetSum-=root->val;
       bool left=hasPathSum1(root->left,targetSum,root);
       bool right=hasPathSum1(root->right,targetSum,root);
       //cout<<left<<" "<<" "<<right<<targetSum<<"\n";
        return left|right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return false;
        //dummy node needed to store previous node
        TreeNode* dummy=NULL;
      return hasPathSum1(root,targetSum,dummy);
    }
};
