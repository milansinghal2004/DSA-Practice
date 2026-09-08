// 11-container-with-most-water.cpp;2p;syntax-help;leetcode

#include<iostream>
#include<vector>
#include<algoritham>
using namespacestd;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxA = 0;

    while(left < right) {
        int h = max(height[left], height[right]);
        int w = right - left;

        maxA = max(maxA, h * w);

        if(height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxA;
}

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << maxArea(height) << endl;

    return 0;
}