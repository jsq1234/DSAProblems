/*

[0,1,3,5,6,8,12,17];

[0,1,2,3,4,8,9,11];

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[2001][2001];
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1 ) return false;
        memset(dp,-1,sizeof(dp));
        return solve(stones,1,1);
    }
    bool solve(vector<int>& stones, int j, int k){
        int n = stones.size();

        if( j == n - 1 ) return dp[j][k] = true;

        if( dp[j][k] != -1 ) return dp[j][k];

        bool f1 = false, f2 = false, f3 = false;

        int it = bsearch(stones,stones[j]+k-1,j,n-1);

        if( it != -1 && k-1 > 0 ){
            int idx = it;
            f1 = solve(stones,idx,k-1);
        }
        
        it = bsearch(stones,stones[j]+k,j,n-1);

        if( it != -1 && k > 0 ){
            int idx = it;
            f2 = solve(stones,idx,k);
        }

        it = bsearch(stones,stones[j]+k+1,j,n-1);

        if( it != -1 && k+1 > 0){
            int idx = it;
            f3 = solve(stones,idx,k+1);
        }

        if(f1 || f2 || f3) return dp[j][k] = true;

        return dp[j][k] = false;
    }

    int bsearch(vector<int>& stones, int val, int start, int end){

        while(start <= end){
            int mid = (start+end)/2;
            if(stones[mid] == val){
                return mid;
            }
            if( stones[mid] > val ){
                end = mid - 1;
            }else{
                start = mid+1;
            }
        }
        return -1;
    }
};
