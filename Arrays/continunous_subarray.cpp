#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> st;
        int n = nums.size();
        long long sum = 0;
        int j = 0;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
            while(*st.rbegin() - *st.begin() > 2){
                st.erase(st.find(nums[j]));
                j++;
            }

            sum += st.size();
        }

        return sum;
    }
};

int main(){
    vector<int> v{34,34,33,34,33,33,32,31,30,31};
    cout<<Solution{}.continuousSubarrays(v);
}