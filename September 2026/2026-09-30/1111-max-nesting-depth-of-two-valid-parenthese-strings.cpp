// 1111-max-nesting-depth-of-two-valid-parenthese-strings.cpp;math-vector;help;leetcode 

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int depth = 0;

        for (char c : seq) {
            if (c == '(') {
                depth++;
                ans.push_back(depth % 2);
            } 
            else {
                ans.push_back(depth % 2);
                depth--;
            }
        }

        return ans;
    }
};