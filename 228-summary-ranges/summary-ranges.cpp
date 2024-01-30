class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
       vector<string>res;
       if(nums.size() == 0) {
           return res;
       }

       int n = nums.size();
       int i=0;
       int j=i+1;

       while(j<n) {
           if(nums[j] == nums[j-1] + 1) {
               j++;
           } else {
               if (i==j-1) {
                   res.push_back(to_string(nums[i]));
               } else {
                   res.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
                   
               }
               i=j;
               j=i+1;
           }
       }
       if (i==j-1) {
            res.push_back(to_string(nums[i]));
        } else {
           res.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));                
        }

       return res;
    }
};