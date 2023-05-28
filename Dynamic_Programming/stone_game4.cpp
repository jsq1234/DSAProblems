#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define ALICE 1
#define BOB 0
class Solution {
public:
    int dp[100001][2];
    bool winnerSquareGame(int n) {
        int rt = sqrt(n);
        if( rt*rt == n ) return true;
        memset(dp,-1,sizeof(dp));
        return solve(n,ALICE);
    }

    bool solve(int n, int turn){
        if( n <= 0 ) return false;
        if( n == 1 ) return true;
        if( dp[n][turn] != -1 ) return dp[n][turn];
        int rt = sqrt(n);
        if( rt*rt == n ) return dp[n][turn] = true;
        int i = 1, j = 2;
        int ans = false;
        while( i <= n ){
            bool opponent = solve(n - i,!turn);
            ans = ans || (!opponent);
            if(ans){
                return dp[n][turn] = true;
            }
            i = j*j;
            j++;
        }
        return dp[n][turn] = ans;
    }
    
};
