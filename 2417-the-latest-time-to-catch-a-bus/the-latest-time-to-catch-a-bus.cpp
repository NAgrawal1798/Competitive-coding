class Solution {
public:
    // Sort both arrays
    // 
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int bus = buses.size();
        int pass = passengers.size();
        int j=0;
        int ans = 0;
        int prev = 0;

        for (int i=0; i<bus; i++) {
            int count=0;
            while(j<pass && passengers[j]<=buses[i] && count<capacity) {
                if (passengers[j] - prev > 1) {
                    ans = passengers[j] - 1;
                }
                prev = passengers[j];
                    j++;
                    count++;
            }
            if (count<capacity && buses[i]-prev>=1) {
                ans = buses[i];
            }
        }
            return ans;
    }
};