// 3483-unique-3digit-even-number;array;self;leetcode

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> nums;
        int n = digits.size();
        for(int i = 0; i < n; i++) {
            if(digits[i] == 0) {
                continue;
            }

            for(int j = 0; j < n; j++) {
                if(j == i) continue;

                for(int k = 0; k < n; k++) {
                    if (k == i || k == j)
                        continue;
                    if (digits[k] % 2 != 0)
                        continue;

                    int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                    nums.insert(number);
                }
            }
        }
        return nums.size();
    }
};