//find rotate image
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]
//  ques link- https://leetcode.com/problems/rotate-image/description/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

      int n=matrix.size();
   
       for(int i=0;i<n;i++)
           for(int j=0;j<i;j++)
               swap(matrix[i][j],matrix[j][i]);
        for(int i=0;i<n;i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};
   