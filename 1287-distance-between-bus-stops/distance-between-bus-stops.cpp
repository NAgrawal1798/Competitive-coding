class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int s = min(start,destination);
        int d = max(start,destination);
        int l = distance.size();
        int dt[2*l];
        for(int i=0;i<l;i++){dt[i]=distance[i];dt[i+l]=distance[i];}
        int s1 = 0;
        int s2 = 0;
        for(int i=s;i<d;i++){s1+=dt[i];}
        for(int i=d;i<s+l;i++){s2+=dt[i];}
        return min(s1,s2);
    }
};