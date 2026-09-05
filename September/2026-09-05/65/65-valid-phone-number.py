# 65-valid-phone-number.cpp;string;help;letcode

class Solution:
    def isNumber(self, s: str) -> bool:
        seen_digit = False
        seen_dot = False
        seen_exponent = False
        digit_after_exponent = True

        for i, ch in enumerate(s):
            if ch.isdigit():
                seen_digit = True
                if seen_exponent:
                    digit_after_exponent = True
            elif ch == '.':
                if seen_dot or seen_exponent:
                    return False
                seen_dot = True
            elif ch == 'e' or ch == 'E':
                if seen_exponent or not seen_digit:
                    return False
                seen_exponent = True
                digit_after_exponent = False
            elif ch == '+' or ch == '-':
                if i != 0 and s[i - 1] != 'e' and s[i - 1] != 'E':
                    return False
            else:
                return False
        return seen_digit and digit_after_exponent