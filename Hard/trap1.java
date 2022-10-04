class Solution {
    public int trap(int[] height) {
        int l[] = new int [height.length];
        int r[] = new int [height.length];
        if(height.length==0)
            return 0;
        l[0] = height[0];
        r[height.length-1]= height[height.length-1];
        for(int i=1 ; i< height.length; i++)
        {
            l[i] = Math.max(height[i], l[i-1]);

        }
        
         for(int i=height.length-2 ; i>= 0; i--)
        {
        r[i]   = Math.max(r[i+1], height[i]);
            
        }
        
        int count =0;
        
        for(int i=0; i< height.length; i++)
        {
            count+= Math.min(l[i], r[i]) - height[i];
        }
        
        return count;
        
    }
}
