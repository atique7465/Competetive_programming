#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>> &logs) {
        map<int, vector<int>> mp;
        int len = logs.size();
        int biggest = 0;
        for (int i = 0; i < len; i++) {
            int time = i == 0 ? logs[i][1] : (logs[i][1] - logs[i - 1][1]);
            biggest = max(biggest, time);
            mp[time].push_back(logs[i][0]);
        }

        len = mp[biggest].size();
        int result = INT_MAX;
        for (int i = 0; i < len; i++) {
            result = min(result, mp[biggest][i]);
        }

        return result;
    }
};