#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <string.h>
using namespace std;

class Solution {
    public:
    int dp[101][101];
    int minCost(int n, vector<int>& cuts) {
            int m = cuts.size();
            sort(cuts.begin(),cuts.end());
            memset(dp,-1,sizeof(dp));
            return solve(cuts,n,0,0,m-1);
        }
    int solve(vector<int>& cuts, int n, int prev, int start, int end){
            if( start > end  ) return 0;
            if( dp[start][end] != -1  ) return dp[start][end];
            int min_cost = INT_MAX;
            for(int i=start; i<=end; i++){
                        int left = solve(cuts,cuts[i],prev,start,i-1);
                        int right = solve(cuts,n,cuts[i],i+1,end);
                        int cost = n - prev;
                        min_cost = min(min_cost, cost + left + right);
                    }
            return dp[start][end] = min_cost;
        }
};
