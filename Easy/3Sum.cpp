class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     
        sort(nums.begin() , nums.end());
        vector<vector<int>>ans;
        
        for(int i=0 ;i<nums.size()-2;i++)
        {
            if(i==0 || (i>0 and nums[i]!=nums[i-1]))
            {
                int lo = i+1;
                int hi=nums.size()-1;
                int sum  =  0 - nums[i];
                while(lo<hi)
                {
                if(nums[lo] + nums[hi] == sum)
                {
                    vector<int>yashi;
                    yashi.push_back(nums[i]);
                    yashi.push_back(nums[lo]);
                    yashi.push_back(nums[hi]);
                    ans.push_back(yashi);
                    
                    while(lo<hi and nums[lo]==nums[lo+1])lo++;
                    while(lo<hi and nums[hi]==nums[hi-1])hi--;
                    
                    lo++;hi--;
                }
                else if(nums[lo] + nums[hi] < sum)
                    lo++;
                else
                    hi--;
                }
            }
        }
     return ans;   
    }
};
