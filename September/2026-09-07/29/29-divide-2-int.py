# 29-divide-2-int;math;help;leetcode

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        negative = (dividend < 0) != (divisor < 0)

        dividend = abs(dividend)
        divisor = abs(divisor)

        quotient = 0

        while dividend >= divisor:
            temp = divisor
            multiple = 1
            while temp + temp <= dividend:
                temp += temp
                multiple += multiple

            dividend -= temp
            quotient += multiple

        if negative:
            quotient = -quotient

        if quotient > INT_MAX:
            return INT_MAX

        if quotient < INT_MIN:
            return INT_MIN

        return quotient