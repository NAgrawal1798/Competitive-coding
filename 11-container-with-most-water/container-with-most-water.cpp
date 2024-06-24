class Solution {
public:
    // it is kind of max rectangle area
    // using stack
    int maxArea(vector<int>& height) {
        // 2 pointer appraoch

        int ans = 0;
        int n = height.size();
        int i=0; 
        int j=n - 1;

        while(i<j) {
            ans = max(ans, (j-i)* min(height[i], height[j]));
            if (height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }

        return ans;
        
    }
};