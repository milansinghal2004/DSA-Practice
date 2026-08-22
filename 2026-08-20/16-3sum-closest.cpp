// 16-3sum-closest.cpp;array-2p;help;leetcode

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int threeSum(vector<int>& nums, int taregt) {
    sort(nums.begin(), nums.end());
    int closestSum = INT_MAX / 2;

    for(int i = 0; i < nums.size(); i++) {
        int left = i + 1;
        int right = nums.size();

        while(left < right) {
            int current_sum = nums[i] + nums[left] + nums[right];

            if(abs(current_sum - taregt) < abs(closestSum - taregt)) {
                closestSum = current_sum;
            }

            if(current_sum < taregt) {
                left++;
            } else if(current_sum > taregt) {
                right--;
            } else {
                return current_sum;
            }
        }
    }

    return closestSum;
}

int main() {
    int n, taregt;
    cin >> n >> taregt;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << threeSum(nums, taregt);

    return 0;
}