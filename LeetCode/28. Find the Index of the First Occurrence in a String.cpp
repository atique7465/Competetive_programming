class Solution {
    int p = 31;
    int mod = 1e9 + 9;
    vector<long long> p_pow;
    vector<long long> h;

public:
    int strStr(string haystack, string needle) {

        int haystackLen = haystack.size(), needleLen = needle.size();
        if(needleLen > haystackLen) return -1;
        
        for (int i = 0; i < haystackLen; i++) p_pow.push_back(i == 0 ? 1 : (p_pow[i - 1] * p) % mod);
                
        long long needleHash = 0;
        for (int i = 0; i < haystackLen; i++) {
            h.push_back(((i == 0 ? 0 : h[i - 1]) + (haystack[i] - 'a' + 1) * p_pow[i]) % mod);
            if(i < needleLen) needleHash = (needleHash + (needle[i] - 'a' + 1) * p_pow[i]) % mod;
        }       
        needleHash = (needleHash * p_pow[haystackLen - 1]) % mod;

        int i = 0, j = needleLen - 1;
        while(j < haystackLen){
            if(getHash(i, j, haystackLen) == needleHash) return i;
            i++, j++;
        }
                
        return -1;
    }
    
    long long getHash(int i, int j, int len) {
        long long hash = (h[j] - (i == 0 ? 0 : h[i - 1]) + mod ) % mod;
        return (hash * p_pow[len - i - 1]) % mod;
    }
};