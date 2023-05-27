#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[101][201];
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        int diff = solve(piles,0,n,1);
        int sum = accumulate(piles.begin(),piles.end(),0);
        return (sum + diff)/2;
    }
    int solve(vector<int>& piles, int i, int n, int M){
        if( i >= n ) return 0;
        if( dp[i][M] != -1 ) return dp[i][M];
        int taken = 0, res = INT_MIN;
        for(int j=i; j<min(n,i + 2*M); j++){
            taken += piles[j];
            res = max(res, taken - solve(piles,j+1,n,max(M,j-i+1)));
        }
        return dp[i][M] = res;
    }
};
