class Solution {
public:
    int twoEggDrop(int n) {
        int a=0,sum=0;
        for(int i=0;i<=n;i++){
            sum+=i;
            if(sum>=n){
                a=i;
                break;
            }
        }
        return a;
    }
};