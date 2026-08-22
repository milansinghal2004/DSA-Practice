// 414-third-max-number.cpp;sorting;bassic-idea-help;leetcode

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int thirdMax(vector<int>& nums) {
    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;

    for (int num : nums) {

        // Ignore duplicates
        if (num == first || num == second || num == third) {
            continue;
        }

        if (num > first) {
            third = second;
            second = first;
            first = num;
        }
        else if (num > second) {
            third = second;
            second = num;
        }
        else if (num > third) {
            third = num;
        }
    }

    // If third maximum doesn't exist
    if (third == LLONG_MIN) {
        return first;
    }

    return third;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << thirdMax(nums) << endl;

    return 0;
}