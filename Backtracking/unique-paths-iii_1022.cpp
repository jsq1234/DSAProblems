/*

[[1,0,0,0],[0,0,0,0],[0,0,2,-1]];

[[1,0,0,0],[0,0,0,0],[0,0,0,2]];

[[0,1],[2,0]];

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int n;
  int m;
  int uniquePathsIII(vector<vector<int>> &grid) {
    n = grid.size();
    m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int p = 0;
    int q = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          p = i;
          q = j;
          int count = 0;
          solve(count, grid, visited, p, q);
          return count;
        }
      }
    }
    return 0;
  }
  void solve(int &count, vector<vector<int>> &grid,
             vector<vector<int>> &visited, int x, int y) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1 || visited[x][y]) {
      return;
    }

    if (grid[x][y] == 2) {
      bool visitedAll = true;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j] == 0 && visited[i][j] == 0 ) {
            visitedAll = false;
            break;
          }
        }
      }
      if (visitedAll)
        count++;
      return;
    }

    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    visited[x][y] = 1;
    solve(count,grid,visited,x+1,y);
    solve(count,grid,visited,x-1,y);
    solve(count,grid,visited,x,y+1);
    solve(count,grid,visited,x,y-1);
    visited[x][y] = 0;
  }
};
