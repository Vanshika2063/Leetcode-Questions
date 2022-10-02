class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        
        if(nums.empty())
            return result;
        
        int n = nums.size();        
        // Step1 => sorting
        sort(nums.begin(),nums.end());
        
        // Step2 => 2-pointer method
        for(int i=0; i<n; i++)
        {
            long long int new_target = target - nums[i];
            for(int j=i+1; j<n; j++)
            {
                long long int final_target = new_target - nums[j];
                
                int head = j+1; // first index of the remaining nums
                int tail = n-1; // last index
                
                while(head<tail)
                {
                    // remaining elements to be found for ans sum
                    int two_sum = nums[head] + nums[tail];
                    // searching for the final_target by 2-pointer method
                    if(two_sum < final_target)
                    {
                        head++;
                    }
                    else if(two_sum > final_target)
                    {
                        tail--;
                    }
                    else
                    {
                        // if two_sum == final_target
                        vector<int> ans(4,0);
                        // ans.push_back(nums[i]);
                        // ans.push_back(nums[j]);
                        // ans.push_back(nums[head]);
                        // ans.push_back(nums[tail]);
                        ans[0] = nums[i];
                        ans[1] = nums[j];
                        ans[2] = nums[head];
                        ans[3] = nums[tail];
                        
                        result.push_back(ans);
                        // Processing the duplicates of number 3
                        while(head < tail && nums[head] == ans[2]) 
                            head++;
                        // Processing the duplicates of number 4
                        while(head < tail && nums[tail] == ans[3]) 
                            tail--;
                    }
                }
                // Processing the duplicates of number 2
                    while(j + 1 < n && nums[j + 1] == nums[j]) 
                        j++;
            }
            // Processing the duplicates of number 1
                    while(i + 1 < n && nums[i + 1] == nums[i]) 
                        i++;
        }
        return resultult;
    }
};