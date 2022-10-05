class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res;
        vector<int> inc(n), dec(n); // inc stores increasing & dec stores decreasing subarray length
        
        dec[0]=1; // for a single element, subarray length will be 1
        for(int i=1;i<n;i++){
            if(nums[i] <= nums[i-1]) // if current element > prev, increase the length
                dec[i]=dec[i-1]+1;
            else
                dec[i]=1; // else, reset the subarray size to 1
        }
        inc[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i] <= nums[i+1]) // if cur element <= next, increase the subarray length
                inc[i]=inc[i+1]+1;
            else
                inc[i]=1; // otherwise start a new subarray with single length
        }
        for(int i=k;i<n-k;i++){
            // if satisfies the condition, add it to result
            if(dec[i-1] >= k and inc[i+1] >= k)
                res.push_back(i);
        }
        return res;
    }
};