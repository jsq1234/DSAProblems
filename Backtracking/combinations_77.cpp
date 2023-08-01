/*

4
2;

1
1;

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> cur;
        vector<vector<int>> ans;
        solve(1,n,k,cur,ans);
        return ans;
    }

    void solve(int i, int n, int k, vector<int>& cur, vector<vector<int>>& ans)
    {

        if (k == 0) {
            ans.push_back(cur);
            return;
        }

        for (int j = i; j <= n; j++) {
            cur.push_back(j);
            solve(j + 1, n, k - 1, cur, ans);
            cur.pop_back();
        }
    }
};
