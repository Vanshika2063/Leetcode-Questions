define ll long long
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int l,r;
        for(int i=0;i<n;i++){
            if(i>=1 and nums[i-1]==nums[i]){
                continue;
            }
            
            l=i+1,r=n-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    ll left=nums[l],right=nums[r];
                    while(l<r and nums[l]==left)l++;
                    while(l<r and nums[r]==right)r--;
                    
                }
                else if(nums[i]+nums[l]+nums[r]<0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        
        return ans;
    }
};

