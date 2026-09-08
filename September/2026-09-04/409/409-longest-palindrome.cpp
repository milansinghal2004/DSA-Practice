// 409-longest-palindrome.cpp;help-syntax;map;leetcode

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for(char ch : s) {
            mp[ch]++;
        }

        int length = 0;
        bool hasOdd = false;

        for(auto it : mp) {
            int count = it.second;

            length += (count / 2) * 2;

            if(count % 2 == 1) {
                hasOdd = true;
            }
        }

        if(hasOdd) {
            length++;
        }

        return length;
    }
};