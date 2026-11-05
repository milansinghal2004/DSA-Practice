# 1021-rm-outermost-parentheses.py;math-stack;help;leetcode\

class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        result = ""
        depth = 0

        for ch in s:
            if ch == '(':
                if depth > 0:
                    result += ch
                depth += 1
            elif ch == ')':
                depth -= 1
                if depth > 0:
                    result += ch

        return result
        