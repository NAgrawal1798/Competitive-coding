class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        vector<int>v;

        int n = skill.size();
        int i=0;
        int j= n-1;

        int sum = skill[i] + skill[j];
        v.push_back(skill[i] * skill[j]);
        i++;
        j--;
        while(i<j) {
            if (skill[i] + skill[j] == sum) {
                v.push_back(skill[i] * skill[j]);
            } else {
                return -1;
            }
            i++;
            j--;
        }
        long long ans = 0;

        for(int i=0; i<v.size() ;i++){
            ans += v[i];
        }
        return ans;
    }
};