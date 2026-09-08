# 16-3sum-closest.cpp;array-2p;self(help for input part);leetcode

from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()

        closest_sum = float('inf')

        for i in range(len(nums) - 2):
            left = i + 1
            right = len(nums) - 1

            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]

                if abs(current_sum - target) < abs(closest_sum - target):
                    closest_sum = current_sum

                if current_sum < target:
                    left += 1
                elif current_sum > target:
                    right -= 1
                else:
                    return current_sum

        return closest_sum


nums = list(map(int, input("Enter the elements of the array: ").split()))
target = int(input("Enter the target: "))

solution = Solution()
result = solution.threeSumClosest(nums, target)

print("Closest Sum:", result)
