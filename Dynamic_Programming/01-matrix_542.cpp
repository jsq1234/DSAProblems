/*

[[0,0,0],[0,1,0],[0,0,0]];

[[0,0,0],[0,1,0],[1,1,1]];

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0) q.push({i,j});
                else mat[i][j] = -1;
            }
        }

        int dist = 0;
        pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int size = q.size();
            dist++;
            while(--size){
                auto [x,y] = q.front();
                q.pop();
                for(int k=0; k<4; k++){
                    auto [dx, dy] = dir[k];
                    int i = x + dx;
                    int j = y + dy;

                    if( i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != -1 ) continue;
                    q.push({i,j});
                    mat[i][j] = dist;
                }
            }
        }

        return mat;
    }
};

