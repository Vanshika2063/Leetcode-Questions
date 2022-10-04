import java.util.ArrayList;
import java.util.List;

//Problem Statement
//Given an m x n matrix, return all elements of the matrix in spiral order.
//     Input: matrix =[ [1,2,3]
//                      [4,5,6]
//                      [7,8,9] ]
// Output: [1,2,3,6,9,8,7,4,5]

//Solution
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        
        int r = matrix.length;
        int c = matrix[0].length;
        int startrow = 0;
       int startcol = 0;
       int endrow = r-1;
       int endcol = c-1;
       int totallen = r*c;
       int count = 0;
       
       ArrayList<Integer> al = new ArrayList<>();
       
       while(count<totallen) {
           
           for(int i=startcol; count<totallen && i<=endcol; i++) {
                al.add(matrix[startrow][i]);
                count++;
           }
           startrow++;
           
           for(int i=startrow; count<totallen && i<=endrow; i++) {
               al.add(matrix[i][endcol]);
               count++;
           }
           endcol--;
           
           for(int i=endcol; count<totallen && i>=startcol; i--) {
               al.add(matrix[endrow][i]);
               count++;
           }
           endrow--;
           
           for(int i=endrow; count<totallen && i>=startrow; i--) {
               al.add(matrix[i][startcol]);
               count++;
           }
           startcol++;
       }
       return al;
    }
    
}