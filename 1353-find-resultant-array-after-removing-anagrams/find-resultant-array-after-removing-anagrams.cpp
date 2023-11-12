class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        vector<string>temp;
        int size = words.size();

        for (int i=0; i<size; i++) {
            string temp_string = words[i];
            sort(temp_string.begin(), temp_string.end());
            temp.push_back(temp_string);
        }

        int i=0;
        int j=i+1;

        if (size == 1) {
            ans.push_back(words[0]);
            return ans;
        }

        while(j<size) {
            cout<<temp[i]<<" "<<temp[j]<<endl;
            if (temp[i] == temp[j]) {
                j++;
            } else {
                ans.push_back(words[i]);
                i=j;
            }
        }
        ans.push_back(words[i]);

        return ans;
    }
};