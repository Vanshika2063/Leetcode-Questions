class Solution {
	public boolean canJump(int[] nums) {
		if(nums[0]==0 && nums.length==1){
			return true;
		}
		else if(nums[0]==0){
			return false;
		}
		else if(nums[0]>0&&nums.length==1){
			return true;
		}
    
    int a = nums.length-1;
    int aa = a;
    
    for(int i =0;i<aa;i++){
        for (int j=0;j<=a;j++){
            if(nums[j]+j<a){
                
            }else{
                a=j;
                break;
            }
        }
        if(a==0){
            return true;
        }
       // System.out.println(a);

    }
    
    return false;
}
}
