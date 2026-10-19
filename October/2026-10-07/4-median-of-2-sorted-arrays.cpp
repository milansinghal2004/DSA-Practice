// 4-median-of-2-sorted-arrays.cpp;math-devide-&-conquer;help;leetcode

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int num1_size = nums1.size();
        int num2_size = nums2.size();
        int total_size = num1_size + num2_size;
        int half = total_size / 2;
        int i = 0, j = 0, prev = 0, curr = 0;

        for(int k = 0 ; k <= half; k++) {
            prev = curr;
            if(i < num1_size && (j >= num2_size || nums1[i] < nums2[j])) {
                curr = nums1[i++];
            } else {
                curr = nums2[j++];
            }
        }

        if(total_size % 2 == 0) {
            return (prev + curr) / 2.0;
        }

        return curr;
    }
};