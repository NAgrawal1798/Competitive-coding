class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int cntM = 0;
        int cntP = 0;
        int cntG = 0;

        int idxM = 0;
        int idxG = 0;
        int idxP = 0;

        for(int i=0; i<garbage.size(); i++) {
            string temp = garbage[i];
            for(int j=0; j<temp.size(); j++) {
                if(temp[j] == 'G') {
                    cntG++;
                    idxG = i;
                } else if(temp[j] == 'M') {
                    cntM++;
                    idxM = i;
                } else if(temp[j] == 'P') {
                    cntP++;
                    idxP = i;
                }
            }
        }

        int ans = 0;
        cout<<idxG<<" "<<idxM<<" "<<idxP<<endl;
        for(int i=0; i<idxG; i++) {
            ans += travel[i];
        }
        for(int i=0; i<idxM; i++) {
            ans += travel[i];
        }
        for(int i=0; i<idxP; i++) {
            ans += travel[i];
        }
        ans  += cntM + cntP + cntG;
        return ans;


    }
};