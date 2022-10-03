class Solution:
    def maxArea(self, height: List[int]) -> int:
        length=len(height)-1
        max_area=0
        right=len(height)-1
        left=0
        while left<right:
            max_area=max(max_area,length*min(height[right],height[left]))
            if height[right]<height[left]:
                right-=1
            else:
                left+=1
            length-=1
        return max_area
