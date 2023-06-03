#include <vector>
#include <iostream>
#include <utility>
using namespace std;

class Solution {
    public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
            int max_time = 0;
            vector<pair<int,int>> visited(n);
            for(int i=0; i<n; i++){
                        max_time = max(max_time, solve(visited,i,manager,informTime,headID));
                    }
            return max_time;
        }
    int solve(vector<pair<int,int>>& visited, int i, vector<int>& man, vector<int>& inf, int hid){
        if( i == hid  ) return 0;
        if(visited[i].first) return visited[i].second; 
        visited[i].first = 1;
        return visited[i].second = solve(visited,man[i],man,inf,hid) + inf[man[i]];
    }

};


/*
 *
 *  ith - employee
 *   man[i] -> his manager
 *    inf[man[i]] -> time his manager takes to inform him.
 *
 *     a[i] -> is the time it takes for ith employee to get informed
 *      a[i] = a[man[i]] + inf[man[i]];
 *       f(i) -> f(man[i]) + inf[man[i]];
 *        f(headID) = 0;
 *
 *         */
