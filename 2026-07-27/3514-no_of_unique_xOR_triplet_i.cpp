// 3513 leetcode No_of_Unique_XOR_Triplet_I;Aray_BitManipulation;Help
 
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 2)
            return n;

        int ans = 1;
        while(ans <= n){
            ans = ans * 2;
        }
        return ans;
    }
};