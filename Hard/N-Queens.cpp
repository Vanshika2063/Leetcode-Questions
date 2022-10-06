//Code by Ashwani-de

// Problem statement :-

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Example:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution
{
  vector<vector<string>> ans;

public:
  bool isSafe(int r, int c, vector<string> &v, int n)
  {
    for (int i = 0; i <= r; i++)
    {
      if (v[i][c] == 'Q')
        return false;
    }

    int row = r, col = c;

    while (row >= 0 && col >= 0)
    {
      if (v[row][col] == 'Q')
        return false;
      row--, col--;
    }

    row = r, col = c;

    while (row >= 0 && col < n)
    {
      if (v[row][col] == 'Q')
        return false;
      row--, col++;
    }
    return true;
  }

  void helper(int r, int n, vector<string> &v)
  {
    if (r == n)
    {
      ans.push_back(v);
      return;
    }
    for (int i = 0; i < n; i++)
    {
      if (isSafe(r, i, v, n))
      {
        v[r][i] = 'Q';
        helper(r + 1, n, v);
        v[r][i] = '.';
      }
    }
  }
  vector<vector<string>> solveNQueens(int n)
  {
    vector<string> v;
    string s(n, '.');
    for (int i = 0; i < n; i++)
      v.push_back(s);
    helper(0, n, v);
    return ans;
  }
};
int main()
{
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector<vector<string>> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++)
    {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}