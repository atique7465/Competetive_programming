#include <bits/stdc++.h>

using namespace std;

class PointInfo {

public:
    int xAxis;
    int startHeight;
    int overLapHeight;
    bool end;

    PointInfo(int xAxis, int startHeight, int overLapHeight, bool end)
            : xAxis(xAxis), startHeight(startHeight), overLapHeight(overLapHeight), end(end) {
    }
};

class Item {

public:
    int height;

    int buildingNo;

    char status;

    Item(int height, int buildingNo, char status)
            : height(height), buildingNo(buildingNo), status(status) {
    }
};

bool operator<(const Item &p1, const Item &p2) {
    return p1.height < p2.height;
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {

        int buildingsCnt = buildings.size();
        vector<char> status(buildingsCnt, 'O');

        map<int, vector<Item>> mp;
        for (int i = 0; i < buildingsCnt; i++) {

            int left = buildings[i][0];
            int right = buildings[i][1];
            int height = buildings[i][2];

            if (mp.find(left) != mp.end()) {
                mp[left].push_back(Item(height, i, 'S'));
            } else {
                mp[left] = {Item(height, i, 'S')};
            }

            if (mp.find(right) != mp.end()) {
                mp[right].push_back({Item(0, i, 'F')});
            } else {
                mp[right] = {Item(0, i, 'F')};
            }
        }

        priority_queue<Item> pq;
        vector<PointInfo *> points;
        for (auto &[k, v]: mp) {
            int startHeight = -1;
            int overLapHeight = -1;
            bool end = false;

            for (int i = 0; i < v.size(); i++) {
                if (v[i].status == 'S') {
                    pq.push(Item(v[i].height, v[i].buildingNo, 'D'));
                    status[v[i].buildingNo] = 'S';
                    startHeight = max(startHeight, v[i].height);
                }

                if (v[i].status == 'F') {
                    status[v[i].buildingNo] = 'F';
                    end = true;
                }
            }

            for (int i = 0; i < v.size(); i++) {
                while (!pq.empty() && status[pq.top().buildingNo] == 'F') {
                    pq.pop();
                }

                if (!pq.empty()) {
                    overLapHeight = max(overLapHeight, pq.top().height);
                }
            }

            points.push_back(new PointInfo(k, startHeight, overLapHeight, end));
        }

        vector<vector<int>> result;
        int lastHeight = -1;
        for (int i = 0; i < points.size(); i++) {
            if (points[i]->startHeight != -1 || points[i]->overLapHeight != -1) {
                int yAxis = max(points[i]->startHeight, points[i]->overLapHeight);
                if (lastHeight != yAxis) {
                    result.push_back({points[i]->xAxis, yAxis});
                    lastHeight = yAxis;
                }
            } else if (points[i]->end) {
                result.push_back({points[i]->xAxis, 0});
                lastHeight = 0;
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> buildings = {{2,  9,  10},
                                     {3,  7,  15},
                                     {5,  12, 12},
                                     {15, 20, 10},
                                     {19, 24, 8}};
    Solution s;
    vector<vector<int>> result = s.getSkyline(buildings);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << "-" << result[i][1] << ", ";
    }
}