// 205-isomorphic-string.cpp;hash_map-string;help

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        int m = s.length();

        for(int i = 0; i < m; i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            if(mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2   ) {
                return false;
            }

            mp1[ch1] = ch2;
            mp2[ch2] = ch1;

        }
        return true;
    }
};