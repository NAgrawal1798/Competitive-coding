class Solution {
public:
    int addDigits(int num) {

        if(num < 10) {
            return num;
        }
        int sum=0;

        int x = num;

        while(x >= 10) {
            sum=0;
            while(x) {
                int digit = x%10;
                x = x/10;
                sum += digit;
            }
            x=sum;
        }
        cout<<sum<<endl;
        
        return sum;
    }
};