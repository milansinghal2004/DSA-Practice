// 556-next-greater-ele.iii.cpp;2p;self;leetcode

class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int i = num.size() - 2;

        while( i >= 0 && num[i] >= num[i + 1]) {
            i--;
        }

        if( i < 0) return -1;

        int j = num.size() - 1;
        while(j >= 0 && num[j] <= num[i]) {
            j--;
        }

        swap(num[i], num[j]);

        reverse(num.begin() + i + 1, num.end());

        long result = stol(num);
        return (result > INT_MAX) ? -1 : (int)result;
    }
};