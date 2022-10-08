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

        //using upper bound concept
        if (mp.find(key) != mp.end() && timestamp >= mp[key][0].first) {
            int lo = 0, hi = mp[key].size();
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (mp[key][mid].first > timestamp) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }

            if (hi != 0) {
                result = mp[key][hi - 1].second;
            }
        }

        return result;
    }
};

class TimeMap_UB_List {

    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap_UB_List() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        int hi = upper_bound(mp[key].begin(), mp[key].end(), timestamp,
                             [](int a, const pair<int, string> &b) { return a < b.first; }) - mp[key].begin();

        return hi == 0 ? "" : mp[key][hi - 1].second;
    }
};

class TimeMap_UB_List_02 {

    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap_UB_List_02() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = upper_bound(mp[key].begin(), mp[key].end(), pair<int, string>(timestamp, ""),
                              [](const pair<int, string> &a, const pair<int, string> &b) { return a.first < b.first; });

        return it == mp[key].begin() ? "" : prev(it)->second;
    }
};

class TimeMap_UB_Map {

    unordered_map<string, map<int, string>> mp;

public:
    TimeMap_UB_Map() {}

    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = mp[key].upper_bound(timestamp);
        return it == mp[key].begin() ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */