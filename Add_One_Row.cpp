Question link = https://leetcode.com/problems/add-one-row-to-tree/

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        
        if(d==1){
            
            TreeNode *ptr = new TreeNode(v, root, nullptr);
            return ptr;
        }

      
        addRow(root, v, d-1);

        return root;
    }

    
    void addRow(TreeNode* parent, int v, int dep){
     
        if(!parent)
            return;

    
        if(dep==1){
            TreeNode *temp;

          
            temp = parent->left; 
            
            parent->left = new TreeNode(v);
        
            parent->left->left = temp;

        
            temp = parent->right;
          
            parent->right = new TreeNode(v);
            
            parent->right->right = temp;
        }
      
        else{
            addRow(parent->left, v, dep-1);
            addRow(parent->right, v, dep-1);
        }
    }
};
