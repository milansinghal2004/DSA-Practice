// 441-arranging-coins.cpp;binary-search;alone;leetcode

#include<iostream>
using namespace std;

int arrangeCoins(int n) {
    int row = 1;
    while(n >= row) {
        n -= row;
        row++;
    }

    return row - 1;
}
 
int main() {
    int n;
    cin  >> n;

    cout << arrangeCoins(n);
    return 0;
}