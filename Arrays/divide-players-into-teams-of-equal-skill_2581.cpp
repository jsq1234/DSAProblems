/*

[3,2,5,1,3,4];

[3,4];

[1,1,2,3];

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(),skill.end());
        int teamCount = n/2;
        int i = 0;
        int j = n-1;
        int prevSum = -1;
        long long ans = 0;
        while(i<=j){
            int curSum = skill[j] + skill[i];
            if(prevSum != -1 && prevSum != curSum) return -1;
            prevSum = curSum;
            ans += ((long long)skill[j])*((long long)skill[i]);
            i++;
            j--;
        }
        return ans;
    }
};