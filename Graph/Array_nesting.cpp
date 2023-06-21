#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n,0);

        int len = 0;
        for(int i=0; i<n; i++){
            int count = 0;
            if(!vis[i]){
                dfs(nums,vis,i,count);
            }
            len = max(len,count);
        }
        return len;
    }

    void dfs(vector<int>& nums, vector<int>& vis,int k, int& count){
        vis[k] = 1;
        count++;
        if(!vis[nums[k]])
            dfs(nums,vis,nums[k],count);
    }
};
