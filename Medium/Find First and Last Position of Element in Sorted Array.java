class Solution {
    public int[] searchRange(int[] nums, int target) {
        
        int i = 0,j = nums.length-1,index = -1;
        
//      find the first occurance of target
        while(i <= j){
            int mid = i + (j-i)/2;
            
            if(nums[mid] == target){
                index = mid; 
                j = mid-1;  // stored result and now traverse in remaining right part
            }
            
            else if(nums[mid] < target)
                i = mid+1; // as mid less than target then move in right part of array
            
            else if(nums[mid] > target)
                j = mid-1; // as mid more than target then move in right part of array
        }
        
        if(index == -1)
            return new int [] {-1,-1};
        
        int res [] = {index, index};
        
//      i = 0; their is no need to initialise 'i' again as now will just search in right most part only 
//      if we want to search only last occurance of target only then use "i = 0"
        
        j = nums.length-1;
        
//      find the last occurance of target        
        
        while(i <= j){
            int mid = i + (j-i)/2;
            
            if(nums[mid] == target){  
                index = mid;
                i = mid+1;  // stored result and now traverse in remaining right part
            }
            else if (nums[mid] < target)
                i = mid+1; // as mid less than target then move in right part of array
            
            else if (nums[mid] > target)
                j = mid-1; // as mid more than target then move in right part of array
        }
        
        res[1] = index;
        
        return res;
    }
}
