class Solution {
    public void rotate(int[][] matrix) {
        int cols=matrix[0].length-1;
        int size=matrix.length-1;
        for(int i=0;i<=size;i++){
            for(int j=i;j<=cols;j++){
                int temp=0;
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(int i=0;i<=size;i++){
            for(int j=0;j<=cols/2;j++){
                int t=0;
                t=matrix[i][j];
                matrix[i][j]=matrix[i][cols-j];
                matrix[i][cols-j]=t;
            }
        }
    }
}
