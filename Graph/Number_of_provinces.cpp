#include "../util.cpp"
class Solution {
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
            vector<vector<int>> adj(n);
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if( i != j  ) {
                        if(isConnected[i][j]){
                            adj[i].push_back(j);
                            adj[j].push_back(i);
                        }

                    }
                }
            }
            vector<int> vis(n,0);
            int count = 0;
            for(int i=0; i<n; i++){
                if(!vis[i]){
                    count++;
                    dfs(i,vis,adj);
                }
            }

            return count;
        }
        void dfs(int i, vector<int>& vis, vector<vector<int>>& adj){
            vis[i] = 1;
            for(int x : adj[i]){
                if(!vis[x])
                    dfs(x,vis,adj);
            }
        }
};
