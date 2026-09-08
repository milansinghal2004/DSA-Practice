// 80-remove-duplicate-from-sorted-array-ii.cpp;array;fun-alone-syntax-help;leetcode

#include<iostream>
#include <vector>
using namespace std;

int removeDup(vector<int>& nums) {
    int k = 0;
    for(int num : nums) {
        if(k  < 2 || num != nums[k - 2]) {
            nums[k] = num;
            k++;
        }
    }

    return k;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k = removeDup(nums);
    cout << k << endl;

    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}