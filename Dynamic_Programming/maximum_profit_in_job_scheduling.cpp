#include <bits/stdc++.h>
using namespace std; 

struct pack{
    int start;
    int end;
    int profit;
};
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i=0; i<n; i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        } 
        vector<int> dp(n,-1);
        sort(jobs.begin(),jobs.end());
        sort(startTime.begin(),startTime.end());
        return solve(0,n,jobs,startTime,dp);
    }

    int solve(int i, int n, vector<vector<int>>& jobs, vector<int>& stime, vector<int>& dp){
        if ( i >= n ) return 0;
        if( dp[i] != -1 ) return dp[i];

        int k = lower_bound(stime.begin(),stime.end(),jobs[i][1]) - stime.begin();
        int pick = jobs[i][2] + solve(k,n,jobs,stime,dp);
        int notpick = solve(i+1,n,jobs,stime,dp);

        return dp[i] = max(pick,notpick);
    }
    
   
};
