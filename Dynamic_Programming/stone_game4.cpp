#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++){
            pq.push({ aliceValues[i] + bobValues[i], i });
        }

        int alice = 0, bob = 0, turn = 0;
        while(!pq.empty()){
            if(!turn){
                alice += aliceValues[pq.top().second];
                pq.pop();
                
            }else{
                bob += bobValues[pq.top().second];
                pq.pop();
            
            }
            turn = !turn;
        }
        
        if(alice == bob) return 0;
        return alice > bob ? 1 : -1;

    }
};
