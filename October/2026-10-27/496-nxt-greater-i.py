# 496-nxt-greater-i.py;stack;self;leetcode

class Solution:
    def nextGreaterElement(self, nums1: list[int], nums2: list[int]) -> list[int]:
        mp = {}
        st = []

        for num in nums2:
            while st and st[-1] < num:
                mp[st.pop()] = num

            st.append(num)

        ans = []
        for num in nums1:
            if num in mp:
                ans.append(mp[num])
            else:
                ans.append(-1)

        return ans