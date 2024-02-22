class Solution {
public:
    int maxi = 0;
    bool isUnique(string s) {
        set<char>st;
        for (auto it: s) {
            st.insert(it);
        }

        if (st.size() == s.size()) {
            return true;
        }

        return false;
    }

    void solve(vector<string>& arr, int i, int n ,string temp) {
        // if we got duplicate then simply return
        if (isUnique(temp) == false) {
            return;
        }

        // base condition
        if (i >= n) {
            int currsize = temp.size();
            maxi = max(maxi, currsize);
            return;
        }

        //take present string
        solve(arr, i+1, n, temp + arr[i]);

        // Dont take present string
        solve(arr, i+1, n, temp);

    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        solve(arr, 0, n, "");// recursion

        return maxi;
    }
};