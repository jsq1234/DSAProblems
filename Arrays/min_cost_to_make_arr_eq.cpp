#include <bits/stdc++.h>
using namespace std;

struct my_pair{
    int arr;
    int cost;
};
class Solution {
public:
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
       int n = nums.size();
       vector<my_pair> v(n,0);
       for(int i=0; i<n; i++){
           v[i] = { nums[i], cost[i] };
       }
       

        

    }
};
