# 93-restore-ip-add.cpp;help;string-backtracking;leetcopde

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        result = []

        def backtrack(index, parts):
            # If we have 4 parts
            if len(parts) == 4:
                # All digits must be used
                if index == len(s):
                    result.append(".".join(parts))
                return

            # Try taking 1, 2, or 3 digits
            for length in range(1, 4):
                if index + length > len(s):
                    break

                part = s[index:index + length]

                # No leading zeros
                if len(part) > 1 and part[0] == '0':
                    break

                # Value must be <= 255
                if int(part) > 255:
                    continue

                parts.append(part)
                backtrack(index + length, parts)
                parts.pop()

        backtrack(0, [])
        return result