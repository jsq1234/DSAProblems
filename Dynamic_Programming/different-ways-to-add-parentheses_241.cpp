/*

"2-1-1";

"2*3-4*5";

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<pair<int,int>,vector<int>> dp;
    vector<int> diffWaysToCompute(string expression) {
        return solve(0,expression.length()-1,expression);
    }
    vector<int> solve(int i, int j, string& exp){
        if( j-i+1 <= 2 ) return {stoi(exp.substr(i,j-i+1))};

        if( dp.find({i,j}) != dp.end() ) return dp[{i,j}];

        vector<int> v;
        for(int k=i; k<=j; k++){
            if(!(exp[k] >= '0' && exp[k] <= '9')){
                vector<int> left = solve(i,k-1,exp);
                vector<int> right = solve(k+1,j,exp);
                if(exp[k] == '+'){
                    for(int x : left){
                        for(int y : right){
                            v.push_back(x+y);
                        }
                    }
                }else if(exp[k] == '-'){
                    for(int x : left){
                        for(int y : right){
                            v.push_back(x-y);
                        }
                    }
                }else if(exp[k] =='*'){
                    for(int x : left){
                        for(int y : right){
                            v.push_back(x*y);
                        }
                    }
                }
            }
        }
        return dp[{i,j}] = v;
    }
};

