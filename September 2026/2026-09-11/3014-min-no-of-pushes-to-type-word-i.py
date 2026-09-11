# 3014-min-no-of-pushes-to-type-word-i.py;self;string;letcode

class Solution:
    def minimumPushes(self, word: str) -> int:
        n = len(word)

        if n <= 8:
            count = n

        elif n <= 16:
            count = 8 + (n - 8) * 2

        elif n <= 24:
            count = 24 + (n - 16) * 3

        else:
            count = 48 + (n - 24) * 4

        return count