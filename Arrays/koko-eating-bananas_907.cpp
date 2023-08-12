/*

[3,6,7,11]
8;

[30,11,23,4,20]
5;

[30,11,23,4,20]
6;

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long low = 1;

        sort(piles.begin(),piles.end());
        

        long long high = *max_element(piles.begin(),piles.end());
        long long res = INT_MAX;

        while(low <= high){
            long long mid = (low + high)/2;
            
            long long time = 0;
            for(int i=0; i<n; i++){
                if(piles[i]%mid == 0){
                    time += piles[i]/mid;
                }else{
                    time += (piles[i]/mid) + 1;
                }
            }

            if(time > h){
                low = mid + 1;
            }else{
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};