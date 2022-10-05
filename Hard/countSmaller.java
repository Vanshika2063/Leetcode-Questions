class Solution {
    public class TreeNode
        {
        int val;
        int count = 1;
        TreeNode left;
        TreeNode right;

        TreeNode(int val)
            {
            this.val = val;
            }
        }

    public int insert_BST(TreeNode root, int val)
        {
        int sum = 0;
        while(true)
            {
            if(val <= root.val)
                {
                root.count++;
                if(root.left != null)
                    root = root.left;

                else
                    {
                    root.left = new TreeNode(val);
                    break;
                    }
                }
            else
                {
                sum+= root.count;

                if(root.right != null)
                    root = root.right;

                else
                    {
                    root.right = new TreeNode(val);
                    break;
                    }
                }
            }
        return sum;
        }
    public List<Integer> countSmaller(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        if(nums == null || nums.length ==0)
            return ans;
        TreeNode root = new TreeNode(nums[nums.length-1]);
        ans.add(0);
        for(int i = nums.length-2; i >=0; i--)
            {
            int count = insert_BST(root, nums[i]);
            ans.add(count);
            }
        Collections.reverse(ans);
        return ans;

    }
}
