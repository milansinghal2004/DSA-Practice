// 433-count-repetitions.cpp;math;leetcode;help

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int s1cnt = 0;
        int s2cnt = 0;
        int index = 0;

        unordered_map<int, pair<int, int>> mp;

        while (s1cnt < n1) {
            s1cnt++;

            for (char ch : s1) {
                if (ch == s2[index]) {
                    index++;

                    if (index == s2.size()) {
                        index = 0;
                        s2cnt++;
                    }
                }
            }

            if (mp.count(index)) {
                int prevS1 = mp[index].first;
                int prevS2 = mp[index].second;

                int cycleS1 = s1cnt - prevS1;
                int cycleS2 = s2cnt - prevS2;

                int remaining = n1 - s1cnt;

                int cycles = remaining / cycleS1;

                s1cnt += cycles * cycleS1;
                s2cnt += cycles * cycleS2;
            }
            else {
                mp[index] = {s1cnt, s2cnt};
            }
        }

        return s2cnt / n2;
    }
};
