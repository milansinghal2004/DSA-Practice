// 457-circular-arrray-loops.cpp;array-2p;help;leetcode

class Solution {
public:
    int nextIndex(vector<int>& nums, int index) {
    int n = nums.size();

    return ((index + nums[index]) % n + n) % n;
}

bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {

        bool forward = nums[i] > 0;

        int slow = i;
        int fast = i;

        while (true) {
            int nextSlow = nextIndex(nums, slow);

            if ((nums[nextSlow] > 0) != forward)
                break;

            if (nextSlow == slow)
                break;

            slow = nextSlow;

            int nextFast = nextIndex(nums, fast);

            if ((nums[nextFast] > 0) != forward)
                break;

            if (nextFast == fast)
                break;

            nextFast = nextIndex(nums, nextFast);

            if ((nums[nextFast] > 0) != forward)
                break;

            if (nextFast == nextIndex(nums, fast))
                break;

            fast = nextFast;

            if (slow == fast)
                return true;
        }
    }

    return false;
}
};