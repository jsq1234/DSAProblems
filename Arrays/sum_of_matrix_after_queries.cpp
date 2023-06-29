#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long sum = 0;
        int m = queries.size();
        set<pair<int,int>> st;
        for(int i=m-1; i>=0; i--){
            if( st.find({queries[i][0],queries[i][1]}) != st.end() ){
                continue;
            }
            sum += queries[i][2]*n;
            st.insert({queries[i][0],queries[i][1]});
        }
        set<pair<int,int>> ft;
        int col_num = 0, row_num = 0;
        for(int i=m-1; i>=0; i--){
            int type = queries[i][0];
            int idx = queries[i][1];
            int val = queries[i][2];
            if( ft.find({queries[i][0],queries[i][1]}) != ft.end()){
                continue;
            }
            if(type){
                sum -= row_num*val;
                col_num++;
            }else{
                sum -= col_num*val;
                row_num++;
            }
            ft.insert({type,idx});
        }
        
        
        return sum;
    }
};
