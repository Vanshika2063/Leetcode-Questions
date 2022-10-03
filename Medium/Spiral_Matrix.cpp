class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return {};
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        vector<int> ans;
		
        while (ans.size() < n*m) {
            for (int i = left; i <= right && ans.size() < n*m ; i++) {
                ans.push_back(matrix[top][i]);
            }
            
            top++;
			
            for (int i = top; i <= bottom  && ans.size() < n*m; i++) {
                ans.push_back(matrix[i][right]);
            }
           
            right--;
			
            for (int i = right; i >= left &&  ans.size() < n*m ; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            
            bottom--;
			
            for (int i = bottom; i >= top  && ans.size() < n*m; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }

};