/*

[[1,0,1],[0,0,0],[1,0,1]];

[[1,0,0],[0,0,0],[0,0,0]];

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long sum = 0;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sum += grid[i][j];
                if(grid[i][j]){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        if(sum == n*m*1L || sum == 0 ){
            return -1;
        }

        int dist = -1;

        vector<pair<int,int>> dirs{{1,0},{0,1},{-1,0},{0,-1}};

        int d1[] = {1,0,-1,0};
        int d2[] = {0,1,0,-1};

        while(!q.empty()){
            int sz = q.size();
            for(int k=0; k<sz; k++){
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx, dy] : dirs){
                    int i = x + dx;
                    int j = y + dy;
                    if(i>=0 && i<n && j>=0 && j<m && !vis[i][j]){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }

            }
            dist++;
        }
        return dist;
    }
};
