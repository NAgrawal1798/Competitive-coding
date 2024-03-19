class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if (n==1 || n==0) {
            return 0;
        }

        int smallest = nums[0];
        int biggest = nums[n - 1];

        int i=0;
        while(i<n) {
            if(smallest != nums[i]) {
                break;
            }
            i++;
        }
        i--;

        int j=n-1;
        while(j>=0) {
            if (biggest != nums[j]) {
                break;
            }
            j--;
        }
        j++;
        if (i==n-1 || j==0) {
            return 0;
        }

        return j-i-1;
    }
};