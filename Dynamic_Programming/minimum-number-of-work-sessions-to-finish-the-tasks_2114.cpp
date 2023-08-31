class Solution {
public:
    int sTime;
    int allOnes;
    int dp[16][1<<15];
    int minSessions(vector<int>& tasks, int sessionTime) {
        sTime = sessionTime;
        int n = tasks.size();
        memset(dp,-1,sizeof(dp));
        allOnes = (1<<n) - 1;
        return solve(tasks,0,0);
    }

    int solve(vector<int>& tasks, int mask, int curTime){
        if(curTime > sTime) return 1e8;
        if(mask == allOnes) return 1;
        if(dp[curTime][mask] != -1) return dp[curTime][mask];
        int ans = 1e8;
        bool flag = true;
        for(int i=0; i<tasks.size(); i++){
            if( mask&(1<<i) ) continue;
            int a = solve(tasks,mask|(1<<i), curTime + tasks[i]);
            if(flag){
                int r = solve(tasks,mask|(1<<i), tasks[i]) + 1;
                ans = min({ans,r,a});

                flag = false; 

                continue;
            }
            int b = solve(tasks,mask|(1<<i), tasks[i]) + 1;
            ans = min({ans,a,b});
        }
        return dp[curTime][mask] = ans;
    }
};