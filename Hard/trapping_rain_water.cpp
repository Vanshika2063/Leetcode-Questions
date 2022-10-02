// Problem:

// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.



// Solution 1
// Time complexity- O(n) Space complexity - O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftmax(n),rightmax(n);
        leftmax[0]=height[0];rightmax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            leftmax[i]=max(leftmax[i-1],height[i]);
            rightmax[n-i-1]=max(rightmax[n-i],height[n-i-1]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=min(rightmax[i],leftmax[i])-height[i];
        return ans;
    }
};




// Solution 2
// Time complexity- O(n) Space complexity - O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int leftmax=0,rightmax=0;
        int i=0,j=height.size()-1;
        while(i<=j){
            if(height[i]<height[j]){
                leftmax=max(leftmax,height[i]);
                ans+=leftmax-height[i];
                i++;
            }
            else{
                rightmax=max(rightmax,height[j]);
                ans+=rightmax-height[j];
                j--;
            }
        }
        return ans;
    }
};