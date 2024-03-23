class Solution {
public:
    // Observations
    // 1. Greedy problem
    // 2. Find the biggest number after remap
    // 3. Find the smallest number after remap

    int minMaxDifference(int num) {
        string maxi = to_string(num);
        string mini = to_string(num);

        int n = to_string(num).size();
        // Find first occurence of non nine char

        char firstEle;
        for(int i=0; i<n; i++) {
            if(maxi[i] != '9') {
                firstEle = maxi[i];
                break;
            }
        }

        char second_firstEle;
        for(int i=0; i<n; i++) {
            if(mini[i] != '0') {
                second_firstEle = mini[i];
                break;
            }
        }

        for(int i=0; i<n; i++) {
            if(maxi[i] == firstEle) {
                maxi[i] = '9';
            }
        }

        for(int i=0; i<n; i++) {
            if(mini[i] == second_firstEle) {
                mini[i] = '0';
            }
        }

        int maxEle = stoi(maxi);
        int minEle = stoi(mini);

        cout<<maxEle<<" "<<minEle<<endl;

        return maxEle - minEle;
    }
};