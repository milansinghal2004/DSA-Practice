// 125 leetcode valid-palindrome.cpp;2p-string;help

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right) {
            while(left < right && !isalnum(s[left])) {
                left++;
            }
            while(left < right && !isalnum(s[right])) {
                right--;
            }

            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};