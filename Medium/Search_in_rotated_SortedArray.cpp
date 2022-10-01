class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n=nums.size();
        int i=0,j=n-1,mid;
        while(i<j)
        {
            mid=i+(j-i)/2;
            if(nums[mid]>nums[j])
            {
                i=mid+1;
            }
            else{
                j=mid;
            }
        }
        int peak=i;
        if(target>=nums[peak] && target<=nums[n-1])
        {
            i=peak,j=n-1;
        }
        else{
            i=0,j=peak-1;
        }
            while(i<=j)
            {
                mid=i+(j-i)/2;
                if(nums[mid]==target)
                {
                    return mid;
                }
                else if(nums[mid]<target)
                {
                    i=mid+1;
                }
                else{
                    j=mid-1;
                }
            }
        return -1;
        
    }
};

        
