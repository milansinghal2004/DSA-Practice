// 3622-check-divisibility-by-digit-sum-and-product.cpp;math;help-syntax;leetcode

#include <iostream>
using namespace std;

bool checkDivisibility(int n) {
    int temp = n;
    int digitSum = 0;
    int digitProduct = 1;

    while (temp > 0) {
        int digit = temp % 10;

        digitSum += digit;
        digitProduct *= digit;

        temp /= 10;
    }

    int total = digitSum + digitProduct;

    return n % total == 0;
}

int main() {
    int n;
    cin >> n;

    if (checkDivisibility(n))
        cout << "true";
    else
        cout << "false";

    return 0;
}