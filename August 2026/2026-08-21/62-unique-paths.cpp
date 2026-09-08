// 62-unique-paths.cpp;maths;self;leetcode

#include<iostream>
#include<vector>
using namespace std;

int uniquePath(int m, int n) {
    vector<vector<int>> way(m, vector<int>(n, 1));

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            way[i][j] = way[i - 1][j] + way[i][j - 1];
        }
    }

    return way[m - 1][n - 1];
}

int main() {
    int n, m;
    cin >> m >> n;
    
    cout << uniquePath(m, n);

    return 0;
}