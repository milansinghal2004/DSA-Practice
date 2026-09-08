// 410-split-array-largest-sum.cpp;search;complete-help-in-logic

class Solution {
public:
    int noOfSubSumAsMid(void<int> &nums, int mid) {
        int sum = 0, count = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(sum + nums[i] > mid) {
                sum = nums[i];
                count++;
            } else {
                sum += nums[i];
            }
        }

        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumlate(nums.begin(), nums.end(), 0);
        int ans = low;
        while(low <= high) {
            int mig = (low + high) / 2;
            int n = noOfSubSumAsMid(nums, mid)

            if( n > k) low = mid + 1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};