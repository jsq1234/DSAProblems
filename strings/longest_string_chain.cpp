#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int check(string& pred, string& cur){
        if( pred.length() + 1 != cur.length() ) return 0;
        int i = 0, j = 0;
        
        while(i < pred.length() && j < cur.length()){
            if( pred[i] != cur[j] ){
                break;
            }
            i++;
            j++;
        }
        string nstr = cur.substr(0,j) + cur.substr(j+1);

        return pred == nstr;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[](string& s1, string& s2){
            return s1.length() < s2.length();
        });

        vector<int> dp(n,1);

        for(int i=1; i<n; i++){
            string s = words[i];
            for(int j=i-1; j>=0; j--){
                if(check(words[j],words[i])){
                    dp[i] = max(dp[i],dp[j] + 1);
                }

            }

        }

        return *max_element(dp.begin(),dp.end());
    }
};
