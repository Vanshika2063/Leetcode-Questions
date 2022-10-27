class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row =  0;//Initially we are at integer 1 as per example 1
        int col = matrix[0].length-1;//at element 15 as per example 1
        while(row<matrix.length && col>=0){
            if(target==matrix[row][col]){
                return true;
            }
            if(target<matrix[row][col]){ // for example we are at row 0 and col 4 
			//means at 15 and 15>target so decrease column by 1 and check, here if we decrease by 1 we will be on 11
                col--;
                continue;
            }
            if(target>matrix[row][col]){
                //moving forward we will end up at 4 which is lesser than target and
				//as the matrix is sorted we won't get the element in that row so we will switch the row
                row++;
            }
        }
        return false; //if the target element is not present
    }
}