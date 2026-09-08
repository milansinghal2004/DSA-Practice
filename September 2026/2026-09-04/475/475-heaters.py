# 475-heaters.cpp;help;array-2p-sorting;leetcode

class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()

        radius = 0

        for house in houses:
            i = bisect_left(heaters, house)

            right = float('inf')
            left = float('inf')

            if i < len(heaters):
                right = heaters[i] - house

            if i > 0:
                left = house - heaters[i - 1]

            radius = max(radius, min(left, right))

        return radius