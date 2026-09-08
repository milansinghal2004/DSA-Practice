# 3950 leetcode exactly-one-consecutive-set-bits-pair.py;array;easy\

class Solution(object):
    def consecutiveSetBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        binary = bin(n)[2:]

        count = 0

        for i in range(len(binary) - 1):
            if binary[i] == '1' and binary[i + 1] == '1':
                count += 1

        return count == 1