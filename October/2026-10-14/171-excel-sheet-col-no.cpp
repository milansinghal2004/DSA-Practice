// 171-excel-sheet-col-no.cpp;string;selkf;leetcode

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;

        for (char ch : columnTitle) {
            result = result * 26 + (ch - 'A' + 1);
        }

        return result;
    }
};2