class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        long long lo = 1, hi = 1LL * time[time.size()-1] * totalTrips;
        while(lo<hi){
            long long mid = (lo+hi)/2;
            long long trips = 0;
            for(int t:time){if(t > mid) break; trips += mid/t;}
            if(trips >= totalTrips) hi = mid;
            else lo = mid+1;
        }
       return lo;
    }
};