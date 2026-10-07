// 151-reverse-words-in-string.cpp;stack;help;leetcode

class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;  
        string word = "";

        for (char ch : s) {
            if (ch == ' ') {
                if (!word.empty()) {
                    words.push(word);
                    word = "";       
                }
            } else {
                word += ch;
            }
        }    

        if (!word.empty()) {
            words.push(word);
        }

        string result = "";
        while (!words.empty()) {
            result += words.top();
            words.pop();

            if (!words.empty()) {
                result += " ";       
            }
        }

        return result;  
    }
};