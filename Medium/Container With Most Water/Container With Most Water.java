/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container
*/

class Solution {
public int maxArea(int[] height) {

    int start=0;
    int end=height.length-1;
    int max=0;
    while(start<end)
    {
        max=Math.max(max,Math.min(height[start],height[end])*(end-start));
        if(height[start]<height[end])
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    return max;
}
}
