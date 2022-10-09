#include <bits/stdc++.h>

using namespace std;

class Solution {

    int dp[50001][51]; // as 1 <= m * n <= 5 * 10^4, so we can easily number every cell uniquely by -> (i * n) + j
    int n, m, dvsor, mod = 1e9 + 7;

public:
    int numberOfPaths(vector<vector<int>> &grid, int k) {
        m = grid.size();
        n = grid[0].size();
        dvsor = k;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, grid);
    }

    int solve(int i, int j, int sum, vector<vector<int>> &grid) {

        if (i >= m || j >= n) {
            return 0;
        }

        if (i == m - 1 && j == n - 1) {
            return (sum + grid[i][j]) % dvsor == 0 ? 1 : 0;
        }

        if (dp[i * n + j][sum] != -1) {
            return dp[i * n + j][sum];
        }

        return dp[i * n + j][sum] = (solve(i + 1, j, (sum + grid[i][j]) % dvsor, grid) +
                                     solve(i, j + 1, (sum + grid[i][j]) % dvsor, grid)) % mod;
    }
};

class Solution_3D_DP {

    vector<vector<vector<int>>> dp;
    int n, m, gk, mod = 1e9 + 7;

public:
    int numberOfPaths(vector<vector<int>> &grid, int k) {
        m = grid.size();
        n = grid[0].size();
        gk = k;
        dp.resize(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        return solve(0, 0, 0, grid);
    }

    int solve(int i, int j, int sum, vector<vector<int>> &grid) {

        if (i >= m || j >= n) {
            return 0;
        }

        if (i == m - 1 && j == n - 1) {
            return (sum + grid[i][j]) % gk == 0 ? 1 : 0;
        }

        if (dp[i][j][sum] != -1) {
            return dp[i][j][sum];
        }

        return dp[i][j][sum] = (solve(i + 1, j, (sum + grid[i][j]) % gk, grid) +
                                solve(i, j + 1, (sum + grid[i][j]) % gk, grid)) % mod;
    }
};
