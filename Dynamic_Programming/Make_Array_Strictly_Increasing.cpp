#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        sort(arr2.begin(),arr2.end());
        return solve(arr1,arr2,0,0,-1);
    }

    int solve(vector<int>& arr1, vector<int>& arr2 , int i, int j, int prev){
        
        if( i >= arr1.size() ){
            return 0;
        }else{
            if( j >= arr2.size() ){
                return -1;
            }
        }
        // get the index which is atleast greater than prev
        int pos = lower_bound(arr2.begin()+j, arr2.end(), prev + 1) - arr2.begin();

        if( prev < arr1[i]){
            int pick = solve(arr1,arr2,i+1,pos+1,arr2[pos]);
            int notpick = solve(arr1,arr2,i+1,pos+1,arr1[i]);
            if( pick == -1 || notpick == -1 ){
                return -1;
            }
            return min(1 + pick, notpick);
        }
        
        int r = solve(arr1,arr2,i+1,pos+1,arr2[pos]);
        
        return r == -1 ? -1 : 1 + r;
        

    }
};


int main(){
    Solution sol;
    vector<int> arr1{1,5,3,6,7};
    vector<int> arr2{4,3,1};

    cout<<sol.makeArrayIncreasing(arr1, arr2)<<endl;
}