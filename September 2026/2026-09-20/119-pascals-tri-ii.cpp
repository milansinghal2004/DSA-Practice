// 119-pascals-tri-ii.cpp;help;array;leetcode

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};

        for (int i = 0; i < rowIndex; i++) {
            vector<int> newRow = {1};

            for (int j = 0; j < row.size() - 1; j++) {
                newRow.push_back(row[j] + row[j + 1]);
            }

            newRow.push_back(1);
            row = newRow;
        }

        return row;
    }
};