// 66-plus-one.cpp;array;help;leetcode

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size();
        vector<int> result(n + 1);

        for(int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            if(sum == 10) {
                result[i + 1] = 0;
                carry = 1;
            } else {
                result[i + 1] = sum;
                carry = 0;
            }
        }

        if(carry == 1) {
            result[0] = 1;
            return result; 
        } else {
            return vector<int>(result.begin() + 1, result.end());
        }
    }
};