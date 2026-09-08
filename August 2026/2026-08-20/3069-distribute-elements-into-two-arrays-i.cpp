// 3069-distribute-elements=into-two-arrays-i.cpp;array;help;leetcode

#include<iostream>
#include<vector>
using namespace std;

vector<int> resultArray(vector<int>& nums) {
    vector<int> arr1;
    vector<int> arr2;
    
    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);
    
    for(int i = 2; i < nums.size() ;i++) {
        if(arr1.back() > arr2.back()) {
            arr1.push_back(nums[i]);
        } else {
            arr2.push_back(nums[i]);
        }
    }
    
    vector<int> result;
    for(int num : arr1) {
        result.push_back(num);
    }
    
    for(int num : arr2) {
        result.push_back(num);
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<int> result = resultArray(nums);
    for(int num : result) {
        cout << num << " ";
    }
    
    return 0;
}