// 74-search-2d-matrix.cpp;matrix;self;leetcode

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            if (target == matrix[i][j]) {
                return true;
            }
        }
    }

    return false;
}

int main() {

    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    if (searchMatrix(matrix, target)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}