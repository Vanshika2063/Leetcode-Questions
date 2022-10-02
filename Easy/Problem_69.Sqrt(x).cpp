class Solution {
public:
    int mySqrt(int x) {
        long int i;
        if(x<=4)
        {
            if(x==4)
                return 2;
            else if(x>=1)
                return 1;
            else
                return 0;
        }
        else if(x>4)
            {
                for(i=2;i<x/2;i++)
                {
                    if((i*i<=x)&&((i+1)*(i+1)>x))
                    {
                         int j=i;
                        return j;
                    }
                        
                }
            }
        return i;
        
    }
};