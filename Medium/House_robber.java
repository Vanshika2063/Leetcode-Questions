package com.company;

public class House_robber {
    public static void main(String[] args) {
        int[] nums = {1,2,3,1};
    int ans = rob(nums);
        System.out.println(ans);
    }

    public static int rob(int[] nums) {
        int in = nums[0];
        int ex = 0;
        int ex_new;

        for(int i=1;i<nums.length;i++){
            ex_new = Math.max(in, ex);
            in = ex + nums[i];
            ex = ex_new;
        }

        return Math.max(in, ex);
    }
}
