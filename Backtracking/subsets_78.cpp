/*

[1,2,3];

[0];

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans, int idx){
        ans.push_back(cur);
        for(int i=idx; i<nums.size(); i++){
            cur.push_back(nums[i]);
            solve(nums,cur,ans,i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        solve(nums,cur,ans,0);
        return ans;
    }
};
