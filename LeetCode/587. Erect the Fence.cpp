class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees) {

        set<vector<int>> hull; 

        int leftMost = findLeftMost(trees);

        int a = leftMost;
        bool leftMostCollinear = false;
        do {

            int b = (a + 1) % trees.size(); 

            for (int i = 0; i < trees.size(); i++)
                if (relativePosition(trees[a], trees[i], trees[b]) < 0)
                    b = i;

            for (int i = 0; i < trees.size(); i++)
                if (i != a && i != b && relativePosition(trees[a], trees[i], trees[b]) == 0 &&
                    inBetween(trees[a], trees[i], trees[b])) {
                    hull.insert(trees[i]);
                    if (i == leftMost) leftMostCollinear = true;
                }

            if(leftMostCollinear) break;

            hull.insert(trees[b]);
            a = b;
        } while (a != leftMost);

        return vector<vector<int>>(hull.begin(), hull.end());
    }

    int findLeftMost(vector<vector<int>> &trees) {
        int leftMost = 0;
        for (int i = 0; i < trees.size(); i++) if (trees[i][0] < trees[leftMost][0]) leftMost = i;
        return leftMost;
    }

    int relativePosition(vector<int> &a, vector<int> &i, vector<int> &b) {
        return (b[0] - a[0]) * (i[1] - a[1]) - (b[1] - a[1]) * (i[0] - a[0]);
    }

    bool inBetween(vector<int> &a, vector<int> &i, vector<int> &b) {
        bool xIn = (i[0] >= a[0] && i[0] <= b[0]) || (i[0] <= a[0] && i[0] >= b[0]);
        bool yIn = (i[1] >= a[1] && i[1] <= b[1]) || (i[1] <= a[1] && i[1] >= b[1]);
        return xIn & yIn;
    }
};