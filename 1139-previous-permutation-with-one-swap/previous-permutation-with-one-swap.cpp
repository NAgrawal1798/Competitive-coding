class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();

        int i=n-2;
        while(i>=0) {
            if(arr[i] > arr[i+1]) {

                int j=n-1;
                while((arr[j] >= arr[i] && j>i ) || arr[j-1] == arr[j] ) {
                    j--;
                }
                swap(arr[i], arr[j]);
                break;
            }
            i--;
        }

        return arr;
    }
};