// leetcode-3514 leetcode No_of_Unique_XOR_Triplet_II;BitManipulation;Help

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // sort all pair
        unordered_set<int> s1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                s1.insert(nums[i] ^ nums[j]);
            }
        }

        // find triplet xor
        unordered_set<int> s2;
        for(int pairXor: s1) {
            for(int &num : nums) {
                s2.insert(pairXor ^ num);
            }
        }

        return s2.size();
    }
};