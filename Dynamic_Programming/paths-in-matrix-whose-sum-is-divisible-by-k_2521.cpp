/*

[[5,2,4],[3,0,5],[0,7,2]]
3;

[[0,0]]
5;

[[7,3,4,9],[2,3,6,2],[2,3,7,0]]
1;

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<vector<ll>>> grid3D;
class Solution {
public:
    const int mod = 1e9 + 7;
    int n;
    int m;
    int numberOfPaths(vector<vector<int>>& grid, int k)
    {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(k, -1)));
        return solve(grid, 0, 0, 0, k, dp) % mod;
    }
    ll solve(vector<vector<int>>& grid, int i, int j, int sum, int k, grid3D& dp)
    {
        if (i >= n || j >= m)
            return 0;
        if (i == n - 1 && j == m - 1) {
            return ((sum + grid[i][j]) % k) == 0;
        }
        if (dp[i][j][sum] != -1)
            return dp[i][j][sum] % mod;
        ll left = solve(grid, i + 1, j, (sum + grid[i][j]) % k, k, dp) % mod;
        ll right = solve(grid, i, j + 1, (sum + grid[i][j]) % k, k, dp) % mod;
        return dp[i][j][sum] = (left + right) % mod;
    }
};
