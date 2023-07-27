/*

"2-1-1";

"2*3-4*5";

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> numbers;
        vector<char> op;
        for(auto x : expression){
            if('0' <= x && x <= '9'){
                numbers.push_back(x-'0');
            }else{
                op.push_back(x);
            }
        }
        return {};
    }

    int solve(int i, vector<int>& nums, vector<char>& op, vector<int>& ans){
        if(!op.size() && nums.size() == 1){
            return nums[0];
        }

        if( i < nums.size() - 1 ){
            int temp = nums[i];
            nums[i] = doOperation(nums[i],nums[i+1],op[i]);
            int val = solve(i+1,nums,op,ans);
            ans.push_back(val);
            nums[i] = temp;
        }

        
        
    }

    int doOperation(int x, int y, char op){
        if( op == '+' ){
            return x + y;
        }else if (op == '-'){
            return x - y;
        }
        return x*y;
    }
};

int main(){
    Solution sol;
    sol.diffWaysToCompute("2*3-4*5+6");
    
}
