// 554-brick-wall.cpp;math-array;leetcode

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> edges;
        int maxEdges = 0;

        for (auto& row : wall) {
            long long position = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                position += row[i];
                edges[position]++;
                maxEdges = max(maxEdges, edges[position]);
            }
        }

        return wall.size() - maxEdges;
    }
};
