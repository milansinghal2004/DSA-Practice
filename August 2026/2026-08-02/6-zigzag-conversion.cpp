// 6 leetcode zigzag-conversion.cpp;string;help

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())  
            return s;

        vector<string> rows(min(numRows, int(s.size())));

        int colRow = 0;
        bool goDown = false;

        for(char c : s) {
            rows[colRow]+= c;
            if(colRow == 0 || colRow == numRows - 1) {
                goDown = !goDown;
            }

            colRow += goDown ? 1 : -1;
        }

        string result;
        for(string row : rows) {
            result += row;
        }

        return result;
    }
};