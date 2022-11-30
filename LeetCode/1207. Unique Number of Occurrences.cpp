class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        unordered_map<int,int>unq;
        for(auto i:arr)
            freq[i]++;
        for(auto const&[k,v]:freq)
            if(unq.find(v)!=unq.end())
                return false;
            else unq[v]=1;
   
        return true;
    }
};