// Leetcode solution to problem #189 Rotate Array
// Medium

// https://leetcode.com/problems/rotate-array/

// code
class RotateArraySolution {
    public void rotate(int[] nums, int k) {
       if(nums.length <= k){
        k = k%nums.length;
    }
        int i = 0;
        int j= nums.length -1;
        
        while(i<j){
            int temp = nums[i];
            nums[i]=nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
        
        i=0;
        j= k-1;
        while(i<j){
            int temp = nums[i];
            nums[i]=nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
        
        i=k;
        j=nums.length -1;
        while(i<j){
            int temp = nums[i];
            nums[i]=nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
}