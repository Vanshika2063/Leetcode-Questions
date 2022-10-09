class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=0; i<nums.size()-1;) {
            if(nums[i] == nums[i+1])
                nums.erase (nums.begin()+i);
            else
                i++;
        }
        
        return nums.size();
    }
};