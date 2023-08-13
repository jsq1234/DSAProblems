/*

[4,2,3,1]
10;

[5,1,8]
6;

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = 1000000000000000000;
        long long ans = 0;
        while(low <= high){
            long long mid = (low + high)/2;
            long long p = 0;
            for(int x : ranks) p += sqrt(mid/x);
            if(p>=cars){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};