#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if( k == 0 ) return nums;

        int n = nums.size();
        
        vector<int> avg(n,-1);
        
        if( k > (n - 1)/2 ) {
            return avg;
        }

 
        vector<long long> prefix(n+1,0);
        for(int i=1; i<=n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
  
        for(int i = k; i < n - k; i++){
            int val = (prefix[i+k+1] - prefix[i-k])/(2*k+1);
            avg[i] = val;
        }

        return avg;

    }
};
