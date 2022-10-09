class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowCount = 0;
        int colCount = col - 1;

        while((rowCount < row) && (colCount >= 0)) {
            int element = matrix[rowCount][colCount];

            if(element == target) {
                return true;
            }

            if(element > target) {
                colCount--;
            }

            if(element < target) {
                rowCount++;
            }
        }

        return false;
    }
};