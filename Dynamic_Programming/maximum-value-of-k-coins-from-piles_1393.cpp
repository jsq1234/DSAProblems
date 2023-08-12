/*

[[1,100,3],[7,8,9]]
2;

[[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]]
7;

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        return solve(piles,n-1,0,k);
    }
    int solve(vector<vector<int>>& piles, int i, int j, int k){

        if(i < 0 || k == 0) return 0;

        int m = piles[i].size();
        if( j >= m ){
            return solve(piles,i-1,0,k);
        }

        int take = piles[i][j] + max(solve(piles,i,j+1,k-1),solve(piles,i-1,0,k-1));
        int not_take = solve(piles,i-1,0,k);

        return max(take,not_take);
    }
};
