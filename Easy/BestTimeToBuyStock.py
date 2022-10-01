#You are given an array prices where prices[i] is the price of a given stock on the ith day.
#You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

class Solution(object):
    def maxProfit(self, prices):
        maxProf = 0
        buy = 0
        sell = 1
        while sell < len(prices):
            curProfit = prices[sell] - prices[buy]
            if prices[buy] < prices[sell]:
                maxProf = max(curProfit,maxProf)
            else:
                buy = sell
            sell += 1
        return maxProf