#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        long long sum = 0;
        for(int x : nums) sum += x;
        int n = nums.size();
        int ret = func(nums,sum/2,n,n/2);

        return sum - 2*ret;
    }

    int func(vector<int>& nums, long long target, int idx, int n){
        if( idx < 0 || target == 0 || n == 0 ) return 0;

        int take = 0, not_take = 0;
        if( target - nums[idx] >= 0 ){
            take = nums[idx] + func(nums,target-nums[idx],idx-1,n-1);
        }
        not_take = func(nums,target,idx-1,n);

        return max(take,not_take);
    }
};