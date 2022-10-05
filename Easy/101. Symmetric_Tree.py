class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def sp(node1, node2):
            if node1 is None:
                return node2 is None
            if node2 is None:
                return False
            return node1.val == node2.val and sp(node1.left, node2.right) and sp(node1.right, node2.left)
        
        if root is None:
            return True
        return sp(root.left, root.right)
