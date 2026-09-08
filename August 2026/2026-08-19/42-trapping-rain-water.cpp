// 42-trapping-rain-water.cpp;array;code-help;leetcode;

#include<iosteam>
using namespace std;

int trap(vector<int>& height) {
    int start = 0;
    int end = height.size() - 1;

    int leftH = 0, right = 0, totalC = 0;

    while(start <= end) {
        leftH = max(leftH, height[start]);
        rightH = max(rightH, height[end]);

        if(leftH < rightH) {
            totalC += leftH - height[start];
            start++;
        } else {
            totalC += rightH - height[end];
            end--;    
        }
    }

    return totalC;
}

int main() {
    int n;
    cin >> n;

    vector<int> height(n);

    for(int i = 0; i < n; i++) {
        cin >> height(n);
    }

    cout << trap(height) << endl;

    return 0;
}