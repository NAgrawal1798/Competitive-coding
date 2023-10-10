class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0, r = 1;
        string prev = "";
        int res = 1;

        while(r < arr.size()) {
            if(arr[r - 1] > arr[r] && prev != ">") {
                res = max(res, r - l + 1);
                r += 1;
                prev = ">";
            }
            else if(arr[r - 1] < arr[r] && prev != "<") {
                res = max(res, r - l + 1);
                r += 1;
                prev = "<";
            }
            else {
                r = arr[r - 1] == arr[r] ? r + 1 : r;
                l = r - 1;
                prev = "";
            }
        }

        return res;
    }
};