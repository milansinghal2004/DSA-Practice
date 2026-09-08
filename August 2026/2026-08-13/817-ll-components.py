# 817-ll-components.py;ll;help

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def numComponents(self, head, nums):
        """
        :type head: Optional[ListNode]
        :type nums: List[int]
        :rtype: int
        """
        numSet = set(nums)
        counter = 0
        temp = head

        while temp:
            if temp.val in numSet:
                if temp.next is None or temp.next.val not in numSet:
                    counter += 1

            temp = temp.next

        return counter