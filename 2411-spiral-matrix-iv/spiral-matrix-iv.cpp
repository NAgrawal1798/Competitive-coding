class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        ListNode* node = head;
        int i = 0;
        int j = 0;
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;
        int direction = 0;

        while (node) {
            ans[i][j] = node->val;
            node = node->next;

            if (direction == 0) {
                if (j == right) {
                    direction = 1;
                    top++;
                    i++;
                } else {
                    j++;
                }
            } else if (direction == 1) {
                if (i == bottom) {
                    direction = 2;
                    right--;
                    j--;
                } else {
                    i++;
                }
            } else if (direction == 2) {
                if (j == left) {
                    direction = 3;
                    bottom--;
                    i--;
                } else {
                    j--;
                }
            } else if (direction == 3) {
                if (i == top) {
                    direction = 0;
                    left++;
                    j++;
                } else {
                    i--;
                }
            }
        }

        return ans;
    }
};
