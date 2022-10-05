// Leetcode solution to problem #1095
// Hard

// https://leetcode.com/problems/find-in-mountain-array

// code
class FindMountainArraySolution {
    public int findInMountainArray(int target, MountainArray arr){
        
        int peak = findPeakIndexInMountainArray(arr);
        
        
        int firstTry = orderAgnosticBinarySearch(arr, 0, peak, target);
        
        if(firstTry != -1){
          return firstTry;
        }
        
        return orderAgnosticBinarySearch(arr,peak+1, arr.length()-1,target);
    }
    
    public int orderAgnosticBinarySearch(MountainArray arr,int start, int end, int target){
       
    
        boolean isAsc = arr.get(start) < arr.get(end);
       
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if(arr.get(mid) == target)
            {
                return mid;
            }
            if(isAsc == true){
                 if(target < arr.get(mid))
                 {
                     end = mid -1;
                 }
                else
                {
                    start = mid +1;
                }
           }else{
                if(target > arr.get(mid)){
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }
        return -1;
      
       
    }
    
    public int findPeakIndexInMountainArray(MountainArray arr)
    {
        int start = 0;
        int end = arr.length()-1;
        
        while(start < end){
            
            int mid = start + (end - start)/2;
            
            if(arr.get(mid) > arr.get(mid + 1) )
            {
                end = mid;
            }
            else{
                start = mid+1;
            }
            
        }
        return start;
    }
}