# 70-climbing-stairs.py;array;self;leetcode

class Solution:
    def climbStairs(self, n: int) -> int:
        arr = [0] * 46 
        arr[0] = 1 
        arr[1] = 1 
        arr[2] = 2 
        
        for i in range(3, n + 1): 
            arr[i] = arr[i - 1] + arr[i - 2] 
            
        return arr[n]