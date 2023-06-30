#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
    int N = s.length();
    int ans = 0;
    int start = 0;
    unordered_map<char, int> map;
    for (int i = 0; i < N; i++) {
        char key = s[i];
        if (map.find(key) != map.end()) {
            int index = map[key];
            int cur_size = map.size();
            ans = max(ans, cur_size);
            
            for (int i = start; i <= index; i++)
            {
                map.erase(s[i]);
            }
            start = index + 1;
        }

        map[key] = i;
    }

    int final_size = map.size();
    ans = max(ans, final_size);
    return ans;
    }
};