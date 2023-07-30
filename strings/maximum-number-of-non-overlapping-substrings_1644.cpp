/*

"adefaddaccc";

"abbaccd";

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string& s)
    {
        int n = s.length();

        unordered_map<char, pair<int, int>> mp;

        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]].first = i;
                mp[s[i]].second = i;
            } else {
                mp[s[i]].second = i;
            }
        }

        vector<vector<int>> arr;
        for (auto& p : mp) {
            int min_idx = p.second.first;
            int max_idx = p.second.second;

            for (int k = min_idx; k <= max_idx; k++) {
                min_idx = min(min_idx, mp[s[k]].first);
                max_idx = max(max_idx, mp[s[k]].second);
            }

            if (min_idx == p.second.first) {
                arr.push_back({ min_idx, max_idx });
            }
        }

        sort(arr.begin(), arr.end(), [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];
        });

        vector<string> ans;
        int prev = -1;
        for(auto& v : arr){
            if( prev < v[0] ){
                ans.push_back(s.substr(v[0],v[1]-v[0]+1));
                prev = v[1];
            }
        }

        sort(ans.begin(),ans.end(),[](string& s1, string& s2){ return s1.length() < s2.length(); });
        return ans;
    }
};
