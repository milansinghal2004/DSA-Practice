// 69-sqrt-x.cpp;array;help;leetcode

class Solution {
public:
    int mySqrt(int x) {
        int start = 1, end = x, result = 0;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(mid <= x / mid) {
                result = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return result;
    }
};