# 3838 leeetcode weighted-word-mapping.py;string-array;help

class Solution(object):
    def mapWordWeights(self, words, weights):
        """
        :type words: List[str]
        :type weights: List[int]
        :rtype: str
        """
        ans = ""

        for word in words:
            sum = 0

            for ch in word:
                sum += weAights[ord(ch) - ord('a')]
            ans += chr(ord('z') - (sum % 26))

        return ans

        1309-dcrypt-string-from-alphabet-to-integer-mapping