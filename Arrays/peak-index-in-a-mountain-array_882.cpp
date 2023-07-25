/*

[0,1,0];

[0,2,1,0];

[0,10,5,2];

[3,4,5,1];

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int start = 0, end = n-1;
        int idx = -1;
        while(end-start >= 2){
            int mid = (start + end)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+ 1]){
                idx = mid;
                break;
            }
            else if ( arr[mid-1] <= arr[mid] && arr[mid] <= arr[mid+1] ){
                start = mid;
            }else if( arr[mid-1] >= arr[mid] && arr[mid] >= arr[mid+1] ){
                end = mid;
            }
        }

        return idx;
    } 
};
