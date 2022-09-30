import java.util.Scanner;
public class KadaneAlgo 
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        // Input for array size
        System.out.println("Enter the size  of array : ");
        int n=sc.nextInt();
        int arr[]=new int[n];

        //Input for array elements
        System.out.println("Enter array values using spaces : ");
        for(int i =0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        SolutionKadaneAlgo s = new SolutionKadaneAlgo();
        int ans=s.maxSubArray(arr);
        System.out.println(ans);
        sc.close();
    }
}
class SolutionKadaneAlgo
{
     public int maxSubArray(int[] nums) 
    {
        int currSum=0;
        int maxSum=nums[0];
        for(int i=0;i<nums.length;i++) 
        {
           currSum=currSum+nums[i];
           if(currSum>maxSum) 
            {
                maxSum=currSum;
            } 
            if(currSum<0)
            {
               currSum=0;  
            }
        }
        return maxSum;
    
    }
}
