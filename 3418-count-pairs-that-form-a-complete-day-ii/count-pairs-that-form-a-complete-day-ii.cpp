class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<long long,long long>mp;
        long long count = 0;
        for(int i=0; i<hours.size(); i++) {
            int rem = hours[i]%24;
            cout<<rem<<endl;
            if (mp.find((24 - rem)%24) != mp.end()) {
                count += mp[(24 - rem)%24];
            }
            mp[rem]++;
        }
        return count;
    }
};