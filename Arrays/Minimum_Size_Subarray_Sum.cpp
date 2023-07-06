#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        int sum = 0;
        int ans = INT_MAX;

        while( i < n && j < n ){
            sum += nums[j];
            if( sum >= target ){
                ans = min(ans, j-i+1);
                while( i < j && sum - nums[i] >= target ){
                    sum -= nums[i];
                    ans = min(ans, j-i);
                    i++;
                }
            }
            j++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
