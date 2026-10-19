// 633-sum-of-sq-num.cpp;math;self;leetcode

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) { 
            double b = sqrt(c - a * a);     
            if (b == (int)b) {              
                return true;                
            }
        }
        return false;                       
    }
};