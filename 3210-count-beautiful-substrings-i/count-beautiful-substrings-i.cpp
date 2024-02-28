class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int beautifulSubstrings(string s, int k) {
        // Always look out in the constraints
        int count = 0;
        int n = s.length();
        for(int i=0; i<n; i++) {
            // counting vowels and consonants
            int vowels = 0;
            int conso = 0;
            for (int j = i; j < n; j++) 
            {
                if (isVowel(s[j]))
                    vowels++;
                else
                    conso++;
            // checking given condition
            if (vowels == conso && (vowels * conso) % k == 0)
                count++;
            }
        }

        return count;
    }
};