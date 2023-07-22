class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>& p1, vector<int>& p2){
            return p1[1] < p2[1];
        });
        int n = intervals.size();
        vector<int> prev = intervals[0];
        int count = 0;
        for(int i=1; i<n; i++){
            vector<int> cur = intervals[i];
            if(cur[0] < prev[1]){
                count++;
                continue;
            }
            prev = cur;
        }

        return count;
    }
};
