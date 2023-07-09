#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[(size_t)1e5+1][2];
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
       int n = nums1.size();
       vector<vector<int>> dp(n,vector<int>(2,-1e4));
       dp[0][0] = 1;
       dp[0][1] = 1;
       for(int i=1; i<n; i++){
           if( nums1[i] < nums1[i-1] && nums1[i] < nums2[i-1] ) {
               dp[i][0] = 1;
           }
           if( nums2[i] < nums1[i-1] && nums2[i] < nums2[i-1]) {
               dp[i][1] = 1;
           }
           if(nums1[i] >= nums1[i-1]){
               dp[i][0] = max(dp[i][0],dp[i-1][0]+1);
           }
           if(nums1[i] >= nums2[i-1]){
               dp[i][0] = max(dp[i][0], dp[i-1][1] + 1 );
           }

           if( nums2[i] >= nums1[i-1] ){
               dp[i][1] = max(dp[i][1], dp[i-1][0]+1);
           }
           if( nums2[i] >= nums2[i-1] ){
               dp[i][1] = max(dp[i][1], dp[i-1][1] + 1);
           }
       }

       int ans = -1e4;

       for(int i=0; i<n; i++){
           ans = max({ans, dp[i][0], dp[i][1]});
       }
       return ans;
    }
};
