// 566-reshape-the-matrix.cpp;matrix;help;leetcode

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int rows = mat.size();
        int cols = mat[0].size();

        if (rows * cols != r * c) {
            return mat;
        }

        vector<vector<int>> result(r, vector<int>(c));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                int index = i * cols + j;

                int newRow = index / c;
                int newCol = index % c;

                result[newRow][newCol] = mat[i][j];
            }
        }

        return result;
    }
};