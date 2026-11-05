# 4-median-of-two-sorted-array.py;math;leetcode;

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
        
# class Solution {
# public:
#     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
#         int num1_size = nums1.size();
#         int num2_size = nums2.size();
#         int total_size = num1_size + num2_size;
#         int half = total_size / 2;
#         int i = 0, j = 0, prev = 0, curr = 0;

#         for(int k = 0 ; k <= half; k++) {
#             prev = curr;
#             if(i < num1_size && (j >= num2_size || nums1[i] < nums2[j])) {
#                 curr = nums1[i++];
#             } else {
#                 curr = nums2[j++];
#             }
#         }

#         if(total_size % 2 == 0) {
#             return (prev + curr) / 2.0;
#         }

#         return curr;
#     }
# };