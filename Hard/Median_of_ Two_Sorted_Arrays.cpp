// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106



//solution
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        vector<int>v(n);
        merge(nums1.begin(), nums1.end(), nums2.begin(),
                   nums2.end(), v.begin());
        int mid = 0;
        double median =0;
        cout<<n<<endl;
        if(n%2 == 0){
            // cout<<"even\n";
            
            mid = n/2;
            int temp = mid-1;
            median = ((double)v[mid] + (double)v[temp])/2;
            // cout<<v[mid]<<' '<<v[temp];
        }
        else{
            // cout<<"odd\n";
            mid = n/2;
            median = v[mid];
        }
        return median;
    }
};