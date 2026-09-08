#14 leetcode longest-common-prefix.py;array-string;syntax-help

class Solution(object):
    def longestCommonPrefix(self, strs):
        output = ""

        for i in range(len(strs[0])):
            x = strs[0][i]

            for j in range(1, len(strs)):
                if i >= len(strs[j]) or strs[j][i] != x:
                    return output

            output += x

        return output
        