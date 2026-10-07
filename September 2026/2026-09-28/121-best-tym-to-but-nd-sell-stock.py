# 121-best-tym-to-but-nd-sell-stock.py;math;self;leetcode

class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        minP = float('inf')
        maxP = 0

        for price in prices:
            if price < minP:
                minP = price
            elif price - minP > maxP:
                maxP = price - minP

        return maxP