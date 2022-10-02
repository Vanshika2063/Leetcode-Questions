/*
 You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example:
Input: prices = [7,1,5,3,6,4]
Output: 5

Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Input: prices = [7,6,4,3,1]
Output: 0

Explanation: In this case, no transactions are done and the max profit = 0.
*/

/* 
 Approach: We just have to find the minimum price of the stock  on any given day
            and selling it on any day after the minimum price day and compute the maximum profit. 
*/


// Time Complexity: O(N) & Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = INT_MAX;
        int maxP = 0;
        
        for(auto x: prices)
        {
            mini = min(mini, x);
            maxP = max(maxP, x-mini);
        }
        
        return maxP;
    }
};