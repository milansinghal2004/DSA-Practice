# 32-longest-valid-parenthesis.cpp;stack;leetcode

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]
        max_length = 0

        for i in range(len(s)):

            if s[i] == '(':
                stack.append(i)

            else:
                stack.pop()

                if not stack:
                    stack.append(i)
                else:
                    length = i - stack[-1]
                    max_length = max(max_length, length)

        return max_length


# Taking input from user
s = input("Enter parentheses string: ")

solution = Solution()

result = solution.longestValidParentheses(s)

print("Longest valid parentheses length:", result)