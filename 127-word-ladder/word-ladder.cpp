#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // BFS
        queue<pair<int, string>> q;
        q.push({1, beginWord}); // Starting from the beginWord with a count of 1
        set<string> st(wordList.begin(), wordList.end());

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int count = q.front().first;
                string word = q.front().second;
                q.pop();

                if (word == endWord) {
                    return count; // If the current word matches endWord, return count
                }

                // Logic to create the new word and insert it into the queue
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (char k = 'a'; k <= 'z'; k++) {
                        word[j] = k;
                        // If the new word exists in the wordList
                        if (st.find(word) != st.end()) {
                            q.push({count + 1, word}); // Push the new word with count incremented
                            st.erase(word); // Erase the word from the set to avoid visiting it again
                        }
                    }
                    word[j] = c;
                }
            }
        }

        return 0; // If endWord is not reachable
    }
};
