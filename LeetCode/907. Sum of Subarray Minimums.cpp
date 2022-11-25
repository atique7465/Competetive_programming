class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        stack<int> st;
        long minSum = 0;
        
        for(int i = 0; i <= arr.size(); i++){
            while(!st.empty() && (i==arr.size() || arr[st.top()]>=arr[i])){
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long cnt = (mid - left) * (right - mid) % mod;
                minSum += (cnt * arr[mid]) % mod;
                minSum %= mod;
            }
            st.push(i);
        }
        
        return minSum;
    }
};