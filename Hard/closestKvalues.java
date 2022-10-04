/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        
        Stack<Integer> s1 =  new Stack<>();
        Stack<Integer> s2 =  new Stack<>();

        inorder(root, false,  target, s1);
        inorder(root, true,  target, s2);

        List<Integer> result = new ArrayList<>();
        
        int count =0;
        
        while( count < k)
        {
            if(s1.isEmpty())
                result.add(s2.pop());
            else if (s2.isEmpty())
                result.add(s1.pop());
            
           else if(Math.abs(s1.peek() - target) < Math.abs(s2.peek() - target))
                result.add(s1.pop());
            else
                result.add(s2.pop());
            
            count++;
        }
        
        return result;
    }
    
    public void inorder(TreeNode root, boolean reverse, double target, Stack<Integer> stack)
    {
        if(root == null)
            return;
            
        inorder( reverse ? root.right: root.left, reverse ,target, stack );
        if((!reverse && root.val > target) ||(reverse && root.val <= target))
                return; 
        stack.push(root.val);
        inorder( reverse ? root.left: root.right, reverse ,target, stack );
        

    }
}
