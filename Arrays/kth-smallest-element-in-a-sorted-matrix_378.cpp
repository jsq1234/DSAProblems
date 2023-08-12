/*

[[1,5,9],[10,11,13],[12,13,15]]
8;

[[-5]]
1;

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<int> pq;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq.push(matrix[i][j]);
                if (pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};
