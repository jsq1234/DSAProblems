/*

[1,2,2];

[0];

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& cur, vector<int>& nums, int idx){
        ans.push_back(cur);
        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            solve(ans,cur,nums,i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(ans,cur,nums,0);
        return ans;
    }
};
