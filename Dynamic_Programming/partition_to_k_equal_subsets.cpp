#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];
        if( sum%k != 0 ) return false;
        
        int r = sum/k;

        vector<int> visited(n,false);

        return solve(nums,0,0,sum/k,k,visited);
    }

    bool solve(vector<int>& nums, int i, int cur_sum, int target, int k, vector<int>& visited){
        if( k == 1 ) return true;

        if( i >= nums.size() ) return false;

        if( cur_sum == target ) return solve(nums,0,0,target,k-1,visited);

        for(int j=i; j<nums.size(); j++){
            if( visited[j] || cur_sum + nums[j] > target ) continue;

            visited[j] = true;
            if(solve(nums,j+1,cur_sum + nums[j],target,k,visited)) return true;
            visited[j] = false;
        }

        return false;
    }

    
};
