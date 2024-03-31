class Solution {
public:
    string minimizeStringValue(string s) {
        // For DSA Question always take your take away
        // and write all the things that came after seeing the question
        // and writee it and check how far are your correct to solve the question.

        // kind of using map
        // we have to store number of occurences and the last index of char
        // then on greedly i can replace it. - this can be done by sorting or priority queue

        vector<int> freq(26, 0);
        string temp = "";
        for(auto c: s) {
            if(c != '?') {
                freq[c - 'a']++;
            }
        }

        for(int ind = 0; ind < s.size(); ind++) {
            if(s[ind] != '?') {
                continue;
            }
            int minFreqInd = 0;
            int minFreq = INT_MAX;
            for(int i =0; i<26; i++) {
                if(minFreq > freq[i]) {
                    minFreq = freq[i];
                    minFreqInd = i;
                }
            }
            temp += ('a' + minFreqInd);
            freq[minFreqInd]++;
        }
        sort(temp.begin(), temp.end());
        for(int i=0, j=0; i<s.size(); i++) {
            if(s[i] == '?') {
                s[i] = temp[j++];
            }
        }

        return s;
    }
};