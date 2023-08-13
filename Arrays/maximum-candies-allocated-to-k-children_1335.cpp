/*

[5,8,6]
3;

[2,5]
11;

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long sum = 0;

        for(int x : candies) sum += x;
        if(sum < k) return 0;

        
        int low = 1;
        int high = *max_element(candies.begin(),candies.end());
        int res = 0;
    
        while(low<=high){
            int mid = (low+high)/2;
            long long p = 0;
            for(int i=0; i<n; i++){
                int num = candies[i]/mid;
                p += num;
            }
            
            if(p>=k){
                res = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return res;
    }
};

