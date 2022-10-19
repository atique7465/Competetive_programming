#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> mp;
        int len = words.size();
        for (int i = 0; i < len; i++) {
            mp[words[i]]++;
        }

        vector<pair<string, int>> v;
        for (auto const &[key, val]: mp) {
            v.push_back({key, val});
        }

        sort(v.begin(), v.end(), compare);

        vector<string> result;
        for (int i = 0; i < k; i++) {
            result.push_back(v[i].first);
        }

        return result;
    }

    static bool compare(pair<string, int> p1, pair<string, int> p2) {
        if (p1.second != p2.second) {
            return p1.second > p2.second;
        } else
            return p1.first < p2.first;
    }
};