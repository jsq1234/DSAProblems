/*

[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCCED";

[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"SEE";

[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCB";

*/
#include <bits/stdc++.h>
using namespace std;
using grid = vector<vector<int>>;
using gridChar = vector<vector<char>>;
class Solution {

public:
    int n;
    int m;
    bool exist(vector<vector<char>>& board, string& word)
    {
        n = board.size();
        m = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vector<vector<int>> vis(n,vector<int>(m,0));
                
                if(solve(board,vis,i,j,0,word)){
                    return true;
                }
              
            }
        }
        return false;
    }
    bool solve(gridChar& board, grid& vis, int i, int j, int k, string& word)
    {

        if (i < 0 || j < 0 || i >= n || j >= m || word[k] != board[i][j] || vis[i][j]) {
            return false;
        }

        if(k == word.size()-1){
            return true;
        }

        vis[i][j] = 1;
        
        int up = solve(board,vis,i-1,j,k+1,word);
        int down = solve(board,vis,i+1,j,k+1,word);
        int left = solve(board,vis,i,j-1,k+1,word);
        int right = solve(board,vis,i,j+1,k+1,word);
        vis[i][j] = 0;
        return up || left || right || down;
    }
};

