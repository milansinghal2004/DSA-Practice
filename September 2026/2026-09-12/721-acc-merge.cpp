// 721-acc-merge.cpp;help-redo;array;leetcode

class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa != pb) {
            parent[pb] = pa;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        unordered_map<string, int> emailToAcc;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (emailToAcc.find(email) != emailToAcc.end()) {
                    unite(i, emailToAcc[email]);
                } 
                else {
                    emailToAcc[email] = i;
                }
            }
        }

        unordered_map<int, vector<string>> groups;
        for (auto& [email, account] : emailToAcc) {
            int root = find(account);
            groups[root].push_back(email);
        }

        vector<vector<string>> result;
        for (auto& [root, emails] : groups) {
            sort(emails.begin(), emails.end());

            vector<string> merged;
            merged.push_back(accounts[root][0]);

            for (string& email : emails) {
                merged.push_back(email);
            }

            result.push_back(merged);
        }

        return result;
    }
};