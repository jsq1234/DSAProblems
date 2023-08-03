/*

[[2,1,1],[1,1,0],[0,1,1]];

[[2,1,1],[0,1,1],[1,0,1]];

[[0,2]];

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n;
    int m;
    int orangesRotting(vector<vector<int>>& grid)
    {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_oranges = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({ i, j });
                }
                if (grid[i][j] == 1) {
                    fresh_oranges++;
                }
            }
        }

        if (fresh_oranges == 0) {
            return 0;
        }
        if (q.empty())
            return -1;

        int total_time = 0;

        vector<pair<int,int>> dir{{1,0},{-1,0},{0,-1},{0,1}};
        while (!q.empty()) {
            int sz = q.size();
            total_time++;
            for (int k = 0; k < sz; k++) {
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx,dy] : dir){
                    int i = x + dx;
                    int j = y + dy;
                    if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1){
                        grid[i][j] = 2;
                        fresh_oranges--;
                        q.push({i,j});
                    }
                }
            }
        }
        if(fresh_oranges){
            return -1;
        }
        return total_time - 1;
    }
    bool check(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
};

