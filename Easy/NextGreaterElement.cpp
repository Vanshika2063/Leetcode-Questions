//he next greater element of some element x in an array is the first greater element that is to the right of x in the same array

#include <bits.stdc++.h>
using namespace std
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for(int i =0; i<nums1.size(); i++){
            int j =0;            

            while(nums1[i]!= nums2[j])
                j++;        

            int c =0;
            for(int k = j; k<nums2.size(); k++){
                if(nums2[j] < nums2[k]){
                    ans.push_back(nums2[k]);
                    c++;
                    break;
            }
            }
			
               if(c ==0)
                    ans.push_back(-1);
            }
        return ans;

    }
};