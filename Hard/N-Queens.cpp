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
public:
  bool isSafe(int row, int col, vector<string> &board, int n)
  {
    int duprow = row;
    int dupcol = col;
    while (row >= 0 && col >= 0)
    {
      if (board[row][col] == 'Q')
      {
        return false;
      }
      row--;
      col--;
    }
    col = dupcol;
    row = duprow;
    while (col >= 0)
    {
      if (board[row][col] == 'Q')
      {
        return false;
      }
      col--;
    }
    col = dupcol;
    row = duprow;
    while (row < n && col >= 0)
    {
      if (board[row][col] == 'Q')
      {
        return false;
      }
      row++;
      col--;
    }
    return true;
  }
  void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
  {
    if (col == n)
    {
      ans.push_back(board);
      return;
    }
    for (int i = 0; i < n; i++)
    {
      if (isSafe(i, col, board, n))
      {
        board[i][col] = 'Q';
        solve(col + 1, board, ans, n);
        board[i][col] = '.';
      }
    }
  }
  vector<vector<string>> solveNQueens(int n)
  {
    vector<string> board(n);
    vector<vector<string>> ans;
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
      board[i] = s;
    }
    solve(0, board, ans, n);
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