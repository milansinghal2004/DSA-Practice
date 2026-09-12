# 3483-unique-3digit-even-number;array;self;leetcode

class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        nums = set()

        for i in range(len(digits)):

            if digits[i] == 0:
                continue

            for j in range(len(digits)):

                if j == i:
                    continue

                for k in range(len(digits)):
                    if k == i or k == j:
                        continue
                    if digits[k] % 2 != 0:
                        continue
                    number = digits[i] * 100 + digits[j] * 10 + digits[k]

                    nums.add(number)
        return len(nums)