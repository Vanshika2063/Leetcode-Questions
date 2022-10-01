public class SetMatrixZero {

    // brute force
    // replace the zero with negative values
    public static void setMatrix(int[][] matrix) {

        int n = matrix.length, m = matrix[0].length;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                if (matrix[row][col] == 0) {
                    //up row
                    int d = row - 1;
                    while (d >= 0)
                        matrix[d--][col] = -1;

                    // down row
                    d = row + 1;
                    while (d < n)
                        matrix[d++][col] = -1;

                    // left col
                    d = col - 1;
                    while (d >= 0)
                        matrix[row][d--] = -1;

                    //right col
                    d = col + 1;
                    while (d < m)
                        matrix[row][d++] = -1;
                }
            }
        }

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (matrix[row][col] == -1) {
                    matrix[row][col] = 0;
                }
            }
        }
    }

    private static void printMatrix(int[][] matrix){

        for (int[] mat : matrix) {
            for (int m_a : mat)
                System.out.print(m_a + " ");
            System.out.println(" ");
         }
    }

    public static void main(String[] args) {

        int[][] matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

        System.out.println("Before Set Zero");
        printMatrix(matrix);

        setMatrix(matrix);

        System.out.println("=====================");

        System.out.println("After Zero");
        printMatrix(matrix);
    }
}