import java.util.*;
public class MergeArray 
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        // Input size of array 1
        System.out.println("Enter the number of elements in array 1 : ");
        int len1=sc.nextInt();

        // Input size of array 2
        System.out.println("Enter the number of elements in array 2 : ");
        int len2=sc.nextInt();

        //Declaring arrays
        int arr1[]=new int[len1+len2];
        int arr2[]=new int[len2];

        //Input elements of array 1
        System.out.println("Enter array 1 values using spaces : ");
        for(int i =0;i<len1;i++)
        {
            arr1[i]=sc.nextInt();
        }

        //Input elements of array 2
        System.out.println("Enter array 2 values using spaces : ");
        for(int i =0;i<len2;i++)
        {
            arr2[i]=sc.nextInt();
        }
        SolutionMergeArray s = new SolutionMergeArray();
        s.merge(arr1,len1,arr2,len2);
        sc.close();
    }
}
class SolutionMergeArray
{
    public void merge(int[] nums1,int m,int[] nums2,int n) 
    {
        for(int i=m;i<m+n;i++)
        {
            nums1[i]=nums2[i-m];
        }
        Arrays.sort(nums1);
        System.out.println("Merged and sorted array : ");
        System.out.println(Arrays.toString(nums1));
        //Hello

    }
}
