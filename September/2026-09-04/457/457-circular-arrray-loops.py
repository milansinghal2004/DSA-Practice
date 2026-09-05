#  457-circular-arrray-loops.cpp;array-2p;help;leetcode

class Solution:
    def nextIndex(self, nums: List[int], index: int) -> int:
        n = len(nums)

        return ((index + nums[index]) % n + n) % n

    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)

        for i in range(n):
            forward = nums[i] > 0

            slow = i
            fast = i

            while True:
                nextSlow = self.nextIndex(nums, slow)

                if (nums[nextSlow] > 0) != forward:
                    break

                if nextSlow == slow:
                    break

                slow = nextSlow

                nextFast = self.nextIndex(nums, fast)

                if (nums[nextFast] > 0) != forward:
                    break

                if nextFast == fast:
                    break

                nextFast = self.nextIndex(nums, nextFast)

                if (nums[nextFast] > 0) != forward:
                    break

                if nextFast == self.nextIndex(nums, fast):
                    break

                fast = nextFast

                if slow == fast:
                    return True

        return False
        