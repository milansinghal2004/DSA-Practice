// 17-letter-combinations-of-a-phone-number.cpp;BACK-TRACK;COMPLETE-HELP-AGAIN;leetcode

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        if (digits.empty()) {
            return result;
        }

        vector<string> letters = {
            "",    
            "",    
            "abc",  
            "def", 
            "ghi",  
            "jkl",  
            "mno", 
            "pqrs", 
            "tuv",  
            "wxyz"  
        };

        string current;

        backtrack(digits, 0, current, result, letters);

        return result;
    }

private:
    void backtrack(string& digits, int index, string& current, vector<string>& result, vector<string>& letters) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        string possibleLetters = letters[digits[index] - '0'];
        for (char ch : possibleLetters) {
            current.push_back(ch);
            backtrack(digits, index + 1, current, result, letters);
            current.pop_back();
        }
    }
};