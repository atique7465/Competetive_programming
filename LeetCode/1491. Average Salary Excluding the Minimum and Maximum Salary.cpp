class Solution {
public:
    double average(vector<int>& salary) {
        int mn = INT_MAX, mx = INT_MIN; double sum = 0;
        for(int v:salary){
           sum += v;
           mn = min(mn, v);
           mx = max(mx, v);
        }

        sum = sum - (mn + mx);
        double avg = sum / (salary.size() - 2);
        return avg;
    }
};