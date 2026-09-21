# 17-letter-combination-of-phone-no.py;backtrack;help;leetcode

class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        if not digits:
            return []
        
        letters = {'2' : "abc", '3' : "def", '4' : "ghi", '5' : "jkl", '6' : "mno", '7' : "pqrs", '8' : "tuv", '9' : "wxyz"}
        result = []

        def backTrack(index, current):
            if index == len(digits):
                result.append(current)
                return 
            
            for ch in letters[digits[index]]:
                backTrack(index + 1, current + ch)
        backTrack(0, "")
        return result