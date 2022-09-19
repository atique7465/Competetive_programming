#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string> &paths) {

        unordered_map<string, vector<pair<string, string>>> mp;

        for (int i = 0; i < paths.size(); i++) {
            string path = paths[i];
            int ln = path.size();
            int j = 0;
            while (j < ln && path[j] != ' ') {
                j++;
            }
            string dir = path.substr(0, j);

            j++;
            while (j < ln) {
                int s = j;
                while (j < ln && path[j] != ' ') {
                    j++;
                }

                if (s < j) {
                    int sos = s;
                    while (path[s] != '.') {
                        s++;
                    }
                    string fileName = path.substr(sos, s - sos);
                    string content = path.substr(s + 5, j - 1 - s - 5);

                    if (mp.find(content) != mp.end()) {
                        mp[content].push_back(make_pair(dir, fileName));
                    } else {
                        mp[content] = {make_pair(dir, fileName)};
                    }
                }
                j++;
            }
        }

        vector<vector<string>> res;
        for (auto const &[k, v]: mp) {
            if (v.size() > 1) {
                vector<string> local;
                for (int k = 0; k < v.size(); k++) {
                    local.push_back(v[k].first + "/" + v[k].second + ".txt");
                }
                res.push_back(local);
            }
        }

        return res;
    }
};

int main() {
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)"};
//    vector<string> paths = {"root/a a.txt(efsfgh) aa.txt(efsfgh) aaa.txt(efsfgh)", "root/c/a 3.txt(efsfgh)","root/c/d 4.txt(efsfgh)"};
    Solution s;
    vector<vector<string>> res = s.findDuplicate(paths);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}