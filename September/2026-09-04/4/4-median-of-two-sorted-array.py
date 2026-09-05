# 4-median-of-two-sorted-array.cpp;self-time-consumed;array-2p;leetcode

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1Size = len(nums1)
        nums2Size = len(nums2)

        t_size = nums1Size + nums2Size
        half = t_size // 2

        i = 0
        j = 0

        prev = 0
        current = 0

        for k in range(half + 1):
            prev = current

            if i < nums1Size and (j >= nums2Size or nums1[i] < nums2[j]):
                current = nums1[i]
                i += 1
            else:
                current = nums2[j]
                j += 1

        if t_size % 2 == 0:
            return (prev + current) / 2.0

        return current