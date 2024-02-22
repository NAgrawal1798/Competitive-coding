class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        // apply dfs and bfs

        // we need to write the generic code

        int n = distance.size();
        int ans1 = 0;
        int start1 = start;
        int destination1 = destination;
        while(start1  != destination1) {
            ans1 += distance[start1];
            start1++;
            if(start1 > n-1) {
                start1 = 0;
            }
        }

        int ans2=0;
        int start2 = start;
        int destination2 = destination;
        while(destination2 != start2) {
            ans2 += distance[destination2];
            destination2++;
            if(destination2 > n-1) {
                destination2 = 0;
            }
        }


        return min(ans1, ans2);
    }
};