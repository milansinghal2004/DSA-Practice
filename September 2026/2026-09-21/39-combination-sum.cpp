// 39-combination-sum.cpp;array;redo;leetcode

class Solution {
public:
    set<vector<int>> s;
    
    void getAll(vector<int>& candidates, int idx, int target, vector<vector<int>> &ans, vector<int> &combi) {
        if(target == 0) {
            if(s.find(combi) == s.end()) {
                ans.push_back(combi);
                s.insert(combi);
            }
            return;
        }
        
        if(idx == candidates.size() || target < 0 ) return;
        combi.push_back(candidates[idx]);
        getAll(candidates, idx, target -  candidates[idx], ans, combi);

        combi.pop_back();
        getAll(candidates, idx + 1, target, ans, combi);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combi;
        getAll(candidates, 0, target, ans, combi);

        return ans;
    }
};