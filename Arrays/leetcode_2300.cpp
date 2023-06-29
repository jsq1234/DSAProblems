#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            int start = 0, end = m-1;
            int idx = m;
            while( start <= end ){
                int mid = (start + end)/2;

                if( 1LL*spells[i]*potions[mid] >= success ){
                    end = mid - 1;
                    idx = mid;
                }else{
                    start = mid + 1;
                }
            }

            ans[i] = (m - idx);
        }

        return ans;


    }
};
