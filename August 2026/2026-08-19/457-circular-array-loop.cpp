// 457-circular-array-loop.cpp;array-2p;help;leetcode

#include<iostream>
using namespace std;

int nextIndex(vector<int> nums, int index) {
    int n = nums.size();

    return ((index + nums[index]) % n + n) % n;
}

bool circularArrayLoop(vector<int> nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        bool forward = nums[i] > 0;

        int slow = i;
        int fast = i;

        while(true) {
            int nextS = nextIndex(nums, slow);
            if((nums[nextS] > 0) != forward) {
                break;
            }

            if(nextS == slow) {
                break;
            }

            slow = nextS;

            int nextFast = nextIndex(nums, fast);

            if((nums[nextFast] > 0) != forward) break;

            if(nextFast == fast) break;

            nextFast = nextIndex(nums, nextFast);

            if((nums[nextFast] > 0) != forward) break;

            if(nextFast == nextIndex(nums, fast)) break;

            fast = nextFast;

            if(slow == fast) return true;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if(circularArrayLoop(nums)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}