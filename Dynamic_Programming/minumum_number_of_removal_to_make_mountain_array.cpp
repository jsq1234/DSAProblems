#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1);
        vector<int> lds(n,1);


        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i] && lis[j]+1 > lis[i]){
                    lis[i] = lis[j]+1;
                }
            }
        }

        for(int i=n-2; i>=0; i--){
            for(int j=n-1; j>i; j--){
                if( nums[j] < nums[i] && lds[j] + 1 > lds[i]){
                    lds[i] = lds[j] + 1;
                }
            }
        }

        int ans = INT_MAX;
        int idx = -1;
        for(int i=1; i<n-1; i++){
            if( lis[i] == 1 || lds[i] == 1 ) continue;
            int a = i+1 - lis[i];
            int b = n-i - lds[i];
            if( ans > a + b ){
                ans = a + b;
                idx = i;
            }
        }

        return ans;
    }
};