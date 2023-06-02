typedef long long ll;
#define all(v) (v).begin(), (v).end()
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumDetonation(vector<vector<int>> &bombs) {
    int n = bombs.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
      ll r = bombs[i][2];
      ll x1 = bombs[i][0];
      ll y1 = bombs[i][1];

      for (int j = 0; j < n; j++) {
        if (i != j) {
          ll x2 = bombs[j][0];
          ll y2 = bombs[j][1];
          ll dst = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
          if (dst <= r * r) {
            adj[i].push_back(j);
          }
        }
      }
    }

    vector<int> exploded(n);
    int ans = 0;

    for (int i = 0; i < n; i++) {
      dfs(i, exploded, adj);
      int count = 0;
      for_each(all(exploded), [&](int x) {
        if (x)
          count++;
      });

      ans = max(ans, count);
      fill(exploded.begin(), exploded.end(), 0);
    }
    return ans;
  }
  void dfs(int i, vector<int> &exploded, vector<vector<int>> &adj) {
    exploded[i] = 1;
    for (int j : adj[i]) {
      if (!exploded[j]) {
        dfs(j, exploded, adj);
      }
    }
  }
};
