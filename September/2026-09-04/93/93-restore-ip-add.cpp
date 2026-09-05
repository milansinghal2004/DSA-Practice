// 93-restore-ip-add.cpp;help;string-backtracking;leetcopde

class Solution {
public:
    vector<string> result;

    void backtrack(string& s, int index, vector<string>& parts) {
        if (parts.size() == 4) {
            if (index == s.length()) {
                result.push_back(
                    parts[0] + "." + parts[1] + "." +
                    parts[2] + "." + parts[3]
                );
            }
            return;
        }
        for (int len = 1; len <= 3; len++) {
            if (index + len > s.length())
                break;

            string part = s.substr(index, len);

            if (part.length() > 1 && part[0] == '0')
                break;

            if (stoi(part) > 255)
                continue;

            parts.push_back(part);

            backtrack(s, index + len, parts);

            parts.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        result.clear();

        vector<string> parts;
        backtrack(s, 0, parts);

        return result;
    }
};