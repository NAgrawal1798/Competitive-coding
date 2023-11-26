class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int area = 0;
        int i=0;
        int top = -1;
        stack<int>st;

        for (int i=0; i<heights.size(); i++) {
            if (st.empty() || heights[st.top()] <= heights[i]) {
                st.push(i);
            }
             else {
                 cout<<i<<endl;
                while(!st.empty() && heights[st.top()] > heights[i]) {
                    int popped_element = st.top();
                    cout<<i<< " "<< popped_element<<endl;
                    st.pop();
                    if (st.empty()) {
                        area = heights[popped_element] * i;
                        cout<<i<< " "<< popped_element<<" "<<area<<endl;
                        maxArea = max(area, maxArea);
                    } else {
                        int top_element = st.top();
                        // cout<<popped_element<<" "<<i<<" "<<top_element<<endl;
                        area = heights[popped_element] * (i - top_element - 1);
                         cout<<i<< " "<< popped_element<<" "<<top_element<<" "<<area<<endl;
                        maxArea = max(area, maxArea);
                    }
                }
                st.push(i);
            }
        }

        int n = heights.size();
        while(!st.empty()) {
            int popped_element = st.top();
            st.pop();
            if (st.empty()) {
                area = heights[popped_element] * n;
                maxArea = max(area, maxArea);
            } else {
                int top_element = st.top();
                // cout<<popped_element<<" "<<n<<" "<<top_element<<endl;
                area = heights[popped_element] * (n - top_element - 1);
                maxArea = max(area, maxArea);
            }
        }
        return maxArea;
    }
};