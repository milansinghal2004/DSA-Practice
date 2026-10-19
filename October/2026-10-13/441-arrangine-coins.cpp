// 441-arrangine-coins.cpp;math;help;leetcode

class Solution {
public:
    int arrangeCoins(int n) {
        int row = 1;

        while (n >= row) {
            n -= row;
            row++;
        }

        return row - 1;
    }
};