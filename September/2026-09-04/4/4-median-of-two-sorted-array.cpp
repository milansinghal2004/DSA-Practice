// 4-median-of-two-sorted-array.cpp;self-time-consumed;array-2p;leetcode

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();

        int t_size = nums1Size + nums2Size;
        int half = t_size / 2;

        int i = 0, j = 0;
        int prev = 0, current = 0;

        for (int k = 0; k <= half; k++) {
            prev = current;

            if (i < nums1Size && (j >= nums2Size || nums1[i] < nums2[j])) {
                current = nums1[i++];
            } else {
                current = nums2[j++];
            }
        }

        if (t_size % 2 == 0) {
            return (prev + current) / 2.0;
        }

        return current;
    }
};