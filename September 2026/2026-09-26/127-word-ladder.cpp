// 127-word-ladder.cpp;queue;help;leetcode

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) {
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string word = q.front();
                q.pop();
                for (int i = 0; i < word.length(); i++) {
                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;

                        if (word == endWord) {
                            return steps + 1;
                        }

                        if (words.find(word) != words.end()) {
                            q.push(word);
                            words.erase(word);
                        }
                    }

                    word[i] = original;
                }
            }

            steps++;
        }

        return 0;
    }
};