#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> v1, v2;
        int n1 = img1[0].size();
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n1; j++){
                if(img1[i][j]){
                    v1.push_back({i, j});
                }
            }
        }

        int n2 = img2[0].size();
        for(int i = 0; i < n2; i++){
            for(int j = 0; j < n2; j++){
                if(img2[i][j]){
                    v2.push_back({i, j});
                }
            }
        }

        map<pair<int,int>, int> done;
        int mxOverlap = 0;
        int v1Len = v1.size();
        int v2Len = v2.size();
        for(int i = 0; i < v1Len; i++){
            for(int j = 0; j < v2Len; j++){
                int xFactor = v2[j].first - v1[i].first;
                int yFactor = v2[j].second - v1[i].second;
                if(done.find({xFactor, yFactor})!= done.end()){
                    continue;
                }
                int cnt = 0;
                for(int k = 0; k < v1Len; k++){
                    int img2X = v1[k].first + xFactor;
                    int img2Y = v1[k].second + yFactor;
                    if(img2X >= 0 && img2X < n2 && img2Y >= 0 && img2Y < n2 && img2[img2X][img2Y]){
                        cnt++;
                    }
                }
                mxOverlap = max(mxOverlap, cnt);
                done[{xFactor, yFactor}] = 1;
            }
        }

        return mxOverlap;
    }
};