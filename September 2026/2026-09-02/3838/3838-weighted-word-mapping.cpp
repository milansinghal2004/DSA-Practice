// 3838-weighted-word-mapping.cpp;string;alone;leetcode
// https://leetcode.com/problems/weighted-word-mapping/

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for  (string word : words) {
            int sum = 0;
            for(char ch : word) {
                sum += weights[ch - 'a'];
            }

            ans += char('z' - (sum % 26));
        }    

        return ans;
    }
};