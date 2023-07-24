/*

[1,2,3];

[0,1];

[1];

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<int> cur;
            vector<vector<int>> ans;
            compute(nums,cur,ans);
            return ans;
        }
        void compute(vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans){
            int n = nums.size();
            if(cur.size() == n ){
                ans.push_back(cur);
                return ;
            }
            for(int i=0; i<n; i++){
                bool take = true;
                for(int j=0; j<cur.size(); j++){
                    if(nums[i] == cur[j]){
                        take = false;
                        break;
                    }
                }
                if(take){
                    cur.push_back(nums[i]);
                    compute(nums,cur,ans);
                    cur.pop_back();
                }
            }
        }
};
