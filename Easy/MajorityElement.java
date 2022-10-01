int elem = 0, cnt = 0;
        
        for (int i=0;i<nums.length;i++){

            if (cnt == 0) elem = nums[i];
            cnt  = (elem == nums[i]) ? cnt + 1 : cnt - 1 ; 
           
        }
        return elem;