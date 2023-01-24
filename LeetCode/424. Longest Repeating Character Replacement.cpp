class Solution {
    unordered_map<char, int> freq;
public:
    int characterReplacement(string s, int k) {
        freq[s[0]] = 1;
        
        int start = 0, end = 0, mxLen = 0, mxCharCnt = 1;
        while(start <= end && end < s.size()){
            mxCharCnt = findMaxCharCnt();
            if(end - start + 1 - mxCharCnt <= k){
                mxLen = max(mxLen, end - start + 1);
                end++;
                if(end < s.size()) freq[s[end]]++;
            }else freq[s[start++]]--;
        }

        return mxLen;
    }

    int findMaxCharCnt(){
        int mx = 0;
        for(auto const&[k,v]:freq) mx = max(mx, v);
        return mx;
    }
};