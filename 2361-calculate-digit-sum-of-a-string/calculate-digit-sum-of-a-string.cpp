class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        string temp = s;

        while(n > k) {
            int i=0;
            int sum = 0;
            temp = "";
            while(i<=n) {
                if ((i!= 0 && (i)%k == 0) || i==n) {
                    temp += to_string(sum);
                    sum = 0;
                    if (i==n) {
                        break;
                    }
                }
                sum += s[i] - '0';
                i++;
            }
            n = temp.size();
            s = temp;
            cout<<s<<endl;
        }
        return s;
    }
};