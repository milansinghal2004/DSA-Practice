// 415-add-strings.cpp;string;help;leetcode but complete
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            
            int digit1 = 0;
            int digit2 = 0;

            if (i >= 0) {
                digit1 = num1[i] - '0';
                i--;
            }

            if (j >= 0) {
                digit2 = num2[j] - '0';
                j--;
            }

            int sum = digit1 + digit2 + carry;

            result += char((sum % 10) + '0');

            carry = sum / 10;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    string num1, num2;

    cin >> num1 >> num2;

    cout << addStrings(num1, num2) << endl;

    return 0;
}