/*

[2,2,2,2,5,5,5,8]
3
4;

[11,13,17,23,29,31,7,5,2,3]
3
5;

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        for(int i=1; i<n; i++){
            arr[i] += arr[i-1]; 
        }
        double thres = threshold;
        int count = 0;
        for(int i=0; i<n-k+1; i++){
            if(i == 0){
                double avg = (double)arr[i+k-1]/(double)k;
                count += avg >= thres;
                continue;
            }
            double sum = arr[i+k-1] - arr[i-1];
            double avg = sum/k;
            count += avg >= thres;
        }

        return count;
    }
};