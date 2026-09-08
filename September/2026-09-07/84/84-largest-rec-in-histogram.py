# 84-largest-rec-in-histogram.cpp;stack;help;leetcode

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        st = []
        maxA = 0
        n = len(heights)

        for i in range(n + 1):
            if i == n:
                curr = 0
            else:
                curr = heights[i]
            
            while st and heights[st[-1]] > curr:
                height = heights[st.pop()]

                if not st:
                    width = i
                else:
                    width = i - st[-1] - 1

                maxA = max(maxA, height * width)

            if i < n:
                st.append(i)
        
        return maxA