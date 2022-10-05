//  https://leetcode.com/problems/target-sum/
public class TargetSum {
    static int count;
    public static void main(String[] args) {
        int[] nums = {1, 1, 1, 1, 1};
        System.out.println(findTargetSumWays(nums, 3));
    }
    public static int findTargetSumWays(int[] nums, int target){
        count = 0;
        TargetSum(nums, target, 0, 0);

        return count;
    }
    public static void TargetSum(int[] nums, int target, int index, int val){
        if(index == nums.length){
            if(target == val){
                count++;
            }
            return;
        }

        TargetSum(nums, target, index+1, val+nums[index]);
        TargetSum(nums, target, index+1, val-nums[index]);
    }
}