#include <bits/stdc++.h>
using namespace std;

struct my_pair{
    int arr;
    int cost;
};

typedef unsigned long long ull;
class Solution {
public:
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
       int n = nums.size();
       vector<my_pair> v;
       for(int i=0; i<n; i++){
           v.push_back({ nums[i], cost[i] });
       }
       
       sort(v.begin(),v.end(),[](my_pair& p1, my_pair& p2){
           return p1.arr < p2.arr;
       });

        

        vector<uint64_t> c1(n,0);
        c1[0] = v[0].cost;
        vector<long long> mul(n,0);
        mul[0] = ((uint64_t)v[0].cost)*((uint64_t)v[0].arr);


        for(int i = 1; i<n; i++ ){
            c1[i] = (uint64_t)c1[i-1] + (uint64_t)v[i].cost;
            mul[i] = mul[i-1] + ((long long)v[i].cost)*((long long)v[i].arr);
        }

        uint64_t max_cost = 1<<31;

        for(int i=0; i<n; i++){
                
            uint64_t a1 = i == 0 ? -c1[n-1] + c1[i] : c1[i-1] - c1[n-1] + c1[i];
            uint64_t a2 = i == 0 ? mul[n-1] - mul[i] : -mul[i-1] + mul[n-1] -mul[i];

            max_cost = min(max_cost, v[i].arr*a1 + a2);
        }


        return max_cost;


    }
};
