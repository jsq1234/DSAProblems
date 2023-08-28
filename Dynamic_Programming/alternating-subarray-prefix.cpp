#include <vector>
#include <iostream>
using namespace std;

vector<int> solve(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n,1);
    for(int i=n-2; i>=0; i--){
        if((nums[i+1] >= 0 && nums[i] < 0) || (nums[i+1] <= 0 && nums[i] > 0 )){
            ans[i] = ans[i+1] + 1;
        }
    }
    return ans;
}

int main(){
    int T = 0;
    cin>>T;

    while(T--){
        int N = 0;
        cin>>N;
        vector<int> nums(N,0);
        for(int i=0; i<N; i++){
            cin>>nums[i];
        }
        vector<int> ans = solve(nums);
        for(int i=0; i<N; i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }

}