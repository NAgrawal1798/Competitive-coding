class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int target = times[targetFriend][0];
        int n = times.size();

        // min heap
        priority_queue<int, vector<int>, greater<int>>available;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>notAvailable;

        sort(times.begin(),times.end());

        for (int i=0; i<n; i++) {
            available.push(i);
        }

        for (auto v: times) {
            int arrival = v[0];
            int dep = v[1];

            while(!notAvailable.empty() && notAvailable.top().first <= arrival) {
                pair<int,int>p = notAvailable.top();
                notAvailable.pop();
                available.push(p.second);
            }
 
            int chair = available.top();
            available.pop();
            notAvailable.push({dep, chair});

            if (arrival == target) {
                return chair;
            }
        }

        return -1;
}

};