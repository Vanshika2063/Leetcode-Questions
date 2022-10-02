// You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:

//     0 <= i < j <= n - 1 and
//     nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.

// Return the number of pairs that satisfy the conditions.


// Solution

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define order_set tree<pair<long,long>, null_type,less<pair<long,long>>, rb_tree_tag,tree_order_statistics_node_update>
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        
        int n=nums1.size();
        long long ans=0;
        vector<long long> t1;
        
        for(int i=0;i<n;i++){
            t1.push_back(nums1[i]-nums2[i]);
        }  
        
        order_set s;
        
        long long curr=0;
        for(auto x: t1){
            long long find=x+diff+1;
            long long num=s.order_of_key({find,-1});
            ans+=(num);
            s.insert({x,curr});
            curr++;

        }
        return ans;
    }
};
