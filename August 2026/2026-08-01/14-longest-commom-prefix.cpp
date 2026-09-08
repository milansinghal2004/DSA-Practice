// 14 leetcode longest_common_prefix;array_String;help

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output = "";
        
        for(int i = 0; i < strs[0].size(); i++) {
            char x = strs[0][i];
            
            for(int j = 1; j < strs.size(); j++) {
                if(i >= strs[j].size() || strs[j][i] != x) {
                    return output;
                }
            }
            
            output += x;
        }
        
        return output;
    }
};