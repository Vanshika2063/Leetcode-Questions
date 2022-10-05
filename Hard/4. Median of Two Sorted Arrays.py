class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
  # median is an element which is half way btw the full array
  # if there are even numbe of  elements , median will be half of the values
    
    # for a given list only one median exists
    
    
    # we will find median by binary search over the sorted arrays....
    # anyone of them,
    # actually the smmaller one !!
    
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2,nums1)

        # smaller one
        n = len(nums1)
        # larger one
        m = len(nums2) 

        l = 0
        h = n
        fullLen = n + m + 1
        halfCount = fullLen / 2
        while l <= h:
            cut1 = (l+h) //2
            cut2 = halfCount - cut1

            l1,r1 = -1e9,1e9
            l2,r2 = -1e9,1e9

            if cut1 > 0:
                l1 = nums1[cut1-1]
            if cut1 <= n-1 :
                r1 = nums1[cut1]
            if cut2 > 0:
                l2 = nums2[cut2-1]
            if cut2 <= m-1 :
                r2 = nums2[cut2]

            # median found
            if l1 <= r2 and l2 <= r1:
                if (fullLen-1) & 1:
                    return max(l1,l2)
                else:
                    return (max(l1,l2) + min(r1,r2)) / 2.0
            elif l1 > r2:
                h = cut1 - 1
            else:
                l = cut1  + 1
        return 0
