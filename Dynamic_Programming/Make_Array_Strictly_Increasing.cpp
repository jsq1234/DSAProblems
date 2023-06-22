#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<int>& arr1, vector<int>& arr2, 
                vector<unordered_map<int,int>>& dp, int i, int prev){
        if( i >= arr1.size() ) {
            return 0;
        }

        if( dp[i].find(prev) != dp[i].end()){
            return dp[i][prev];
        }

        int take = INT_MAX, not_take = INT_MAX;
        if( prev < arr1[i] ){
            not_take = solve(arr1,arr2,dp,i+1,arr1[i]);
        }

        int idx = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();

        if( idx < arr2.size() ){
            take = solve(arr1,arr2,dp,i+1,arr2[idx]);
        }

        if( take == INT_MAX ){
            return dp[i][prev] = not_take;
        }

        return dp[i][prev] = min(take+1,not_take);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        vector<unordered_map<int,int>> dp(2001);
        int val = solve(arr1,arr2,dp,0,-1);
        return val == INT_MAX ? -1 : val;
    }
};
