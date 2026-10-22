// 1089-dup-zeroes.cpp;leetcode;help

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeroes = 0;
        for(int x : arr) {
            if(x == 0) zeroes++;
        }

        int i = n - 1, j = n + zeroes - 1;

        while(i >= 0 && j >= 0) {
            if(j < n) arr[j] = arr[i];
            if(arr[i] == 0) {
                j--;
                if(j < n) {
                    arr[j] = 0;
                }

                i--;
                j--;
            }
        }
    }
};