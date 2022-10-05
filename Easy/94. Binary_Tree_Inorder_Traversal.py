class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans=[root]
        fi=[]
        def trv(root,fi):
            if root:
                trv(root.left,fi)
                fi.append(root.val)
                trv(root.right,fi)
            
        trv(root,fi)
        
        return fi
