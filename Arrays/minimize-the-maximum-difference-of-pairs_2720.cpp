/*

[10,1,2,7,1,3]
2;

[4,2,1,2]
1;

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int high = nums[n - 1] - nums[0];
        int low = 0;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (countPairs(nums, p, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    bool countPairs(vector<int>& nums, int p, int val)
    {
        for (int i = 1; i < nums.size();) {
            if (nums[i] - nums[i - 1] <= val) {
                p--;
                i += 2;
            } else {
                i++;
            }
        }
        return p <= 0;
    }
};
