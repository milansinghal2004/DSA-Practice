# 1477-find-2-non-overlapping-sub-array-each-with-target-sum.py;array-sliding-window;help;leetcode

class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        n = len(arr)
        left = 0
        total = 0
        ans = float('inf')
        best = [float('inf')] * n

        for right in range(n):
            total += arr[right]

            while left <= right and total > target:
                total -= arr[left]
                left += 1
            
            if total == target:
                length = right - left + 1

                if left > 0 and best[left - 1] != float('inf'):
                    ans = min(ans, length + best[left - 1])

                if right == 0:
                    best[right] = best[right - 1]
                else:
                    best[right] = min(best[right - 1], length)
            else:
                if right > 0:
                    best[right] = best[right - 1]
        
        return -1 if ans == float('inf') else ans