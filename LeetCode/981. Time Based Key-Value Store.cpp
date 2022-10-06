#include <bits/stdc++.h>

using namespace std;

class TimeMap {

    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if (mp.find(key) != mp.end()) {
            mp[key].push_back(make_pair(timestamp, value));
        } else {
            mp[key] = {make_pair(timestamp, value)};
        }
    }

    string get(string key, int timestamp) {
        string result = "";

        if (mp.find(key) != mp.end() && timestamp >= mp[key][0].first) {
            int lo = 0, hi = mp[key].size();
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (mp[key][mid].first <= timestamp) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }

            if (hi != 0) {
                result = mp[key][hi - 1].second;
            }
        }

        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */