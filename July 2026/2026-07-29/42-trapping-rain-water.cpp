// 42 leetcode TrappingRainWater;Array_TwoPointer;With_Help

class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0, end = height.size() - 1, leftM = 0, rightM = 0, totalM = 0;
        while(start <= end)  {
            leftM = max(leftM, height[start]);
            rightM = max(rightM, height[end]);

            if(leftM < rightM) {
                totalM += leftM - height[start];
                start++;
            } else {
                totalM += rightM - height[end];
                end--;
            }
        }

        return totalM;
    }
};