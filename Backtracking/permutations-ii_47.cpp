/*

[1,1,2];

[1,2,3];

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {        
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(),nums.end());
        compute(nums,cur,ans);
        for_each(ans.begin(),ans.end(),[=](vector<int>& p){
            for(int& x : p) {
                x = nums[x];
            }
        });
        set<vector<int>> st(ans.begin(),ans.end());
        vector<vector<int>> newAns(st.begin(),st.end());
        return newAns;
    }

    void compute(vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans){
        int n = nums.size();
        if(cur.size() == n){
            ans.push_back(cur);
            return ;
        }

        for(int i=0; i<n; i++){
            bool contains = false;
            for(int x : cur){
                if(x == i){
                    contains = true;
                    break;
                }
            }
            if(contains) continue;
            cur.push_back(i);
            compute(nums,cur,ans);
            cur.pop_back();
        }
    }
};
