// 438 leetcode find_anagrams;string_2p_sliding;help

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())  return {};

        vector<int> suffix(26,0);
        vector<int> prefix(26,0);

        int left = 0, right = 0;

        while(right < p.size()) {
            suffix[s[right] - 'a']++;
            prefix[p[right] - 'a']++;
            right++;
        }
        right--;

        vector<int> ans;
        while(right < s.size()) {
            if(suffix == prefix) {
                ans.push_back(left);
            }

            suffix[s[left] - 'a']--;
            left++;
            right++;

            if(right != s.size()) {
                suffix[s[right] - 'a']++;
            }
        }

        return ans;
    }
};