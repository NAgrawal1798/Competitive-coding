class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int timeTaken = 0;

        // naive approach
        int i=0;
        while(tickets[k]) {
            if(tickets[i] > 0) {
                timeTaken++;
                tickets[i]--;
            }
            i++;
            if (i >= tickets.size()) {
                i=0;
            }
        }

        return timeTaken;

    }
};