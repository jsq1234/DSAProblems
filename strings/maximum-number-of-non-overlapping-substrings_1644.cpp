/*

"adefaddaccc";

"abbaccd";

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string& s) {
        int n = s.length();

        unordered_map<char,pair<int,int>> mp;

        for(int i=0; i<n; i++){
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]].first = i;
                mp[s[i]].second = i;
            }else{
                mp[s[i]].second = i;
            }
        }

        vector<string> ans;

        for(int i=0; i<n; i++){
            int first_index = mp[s[i]].first;
            if( first_index < i ){
                continue;
            }
            int last_index = mp[s[i]].second;
        }
    }
};

int main(){
    Solution sol;
    string s = "adefaddaccc";
    string s2 = "abbabcd";
    sol.maxNumOfSubstrings(s);
    sol.maxNumOfSubstrings(s2);
}
