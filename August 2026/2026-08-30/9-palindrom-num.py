# 9-palindrom-num.py;math;leetcode

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False

        number = str(x)
        left = 0
        right = len(number) - 1

        while left < right:
            if number[left] != number[right]:
                return False

            left += 1
            right -= 1

        return True