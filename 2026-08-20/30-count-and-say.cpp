// 30-count-and-say.cpp;string;help;leetcode

#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n) {
    string result = "1";

    for (int i = 1; i < n; i++) {
        string next = "";

        int count = 1;

        for (int j = 1; j < result.length(); j++) {

            if (result[j] == result[j - 1]) {
                count++;
            }
            else {
                next += to_string(count);
                next += result[j - 1];

                count = 1;
            }
        }

        next += to_string(count);
        next += result.back();

        result = next;
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    cout << countAndSay(n);

    return 0;
}