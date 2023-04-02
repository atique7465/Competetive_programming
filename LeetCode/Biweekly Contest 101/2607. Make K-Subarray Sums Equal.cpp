class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long res = 0, median = 0;
        for(int i = 0; i < arr.size(); i++){
            vector<long long> v;
            for(int j = i; arr[j] != 0; j = (j+k)%arr.size()){
                v.push_back(arr[j]); arr[j] = 0;
            }
            if(v.size() > 0){
            sort(v.begin(), v.end());
            if(v.size() % 2 == 1) median = v[((v.size()+1)/2)-1];
            else median = (v[(v.size()/2)-1] + v[v.size()/2])/2;
            for(long long k:v) res += abs(k-median);
            }
        }
        return res;
    }
};