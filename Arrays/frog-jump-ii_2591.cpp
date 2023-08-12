/*

[0,2,5,6,7];

[0,3,9];

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if(n == 2){
            return stones[n-1] - stones[0];
        }
        int maxJp = 0;
        for(int i=0; i<n-2; i++){
            maxJp = max(maxJp, stones[i+2] - stones[i]);
        }
        return maxJp;
    }
};