class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        
        vector<vector<int>> visited(N,vector<int>(M,0));
        if(grid[0][0] || grid[N-1][M-1]) return -1;
        queue<vector<int>> Q;
        Q.push({0,0,0});
        visited[0][0] = 1;
        vector<pair<int,int>> D = {{0,1},{0,-1},{1,0},{1,-1},{-1,0},{-1,1},{1,1},{-1,-1}};
        
        while(!Q.empty()){
            
            vector<int> t = Q.front();
            
            Q.pop();
            
            if( t[0] == N-1 && t[1] == M-1 ){
                return t[2] + 1;
            }
            
            for(int k=0; k<8; k++){
                int i = t[0] + D[k].first;
                int j = t[1] + D[k].second;
                
                if(check(grid,visited,i,j)){
                    Q.push({i,j, t[2] + 1});
                    visited[i][j] = 1;
                }
            }
        }
        
        return -1;
    }
    bool check(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j){
        return ( i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && !visited[i][j] && grid[i][j] == 0);
    }
};
