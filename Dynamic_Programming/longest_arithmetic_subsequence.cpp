#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n+1);
        
        int ans = 2;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                dp[i][nums[i]-nums[j]] = 2;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int d = nums[i] - nums[j];
                if( dp[j].find(d) != dp[j].end() ){
                    if( dp[j][d] + 1 > dp[i][d] ){
                        dp[i][d] = dp[j][d] + 1;
                        ans = max(ans, dp[i][d]);
                    }
                       

                   
                }


                
            }
        }
        return ans;
    }
};


/*
 dp[i][j] => the length of subsequence st. d is j

*/
