#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // Convert the paragraph to lowercase
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);

        map<string, int> mp;

        int i = 0;
        int n = paragraph.length();

        while (i < n) {
            if (isalpha(paragraph[i])) {
                int j = i + 1;
                while (j < n && isalpha(paragraph[j])) {
                    j++;
                }
                string word = paragraph.substr(i, j - i);
                if (find(banned.begin(), banned.end(), word) == banned.end()) {
                    mp[word]++;
                }
                i = j;
            } else {
                i++;
            }
        }

        string mostCommon = "";
        int maxFreq = 0;

        for (auto it : mp) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                mostCommon = it.first;
            }
        }

        return mostCommon;
    }
};
