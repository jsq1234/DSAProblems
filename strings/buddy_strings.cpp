#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if( s.length() != goal.length() ) return false;

        
        int count = 0;
        int n = s.length();
        int idx1 = 0, idx2 = 0;
        int freq[26];
        memset(freq,0,sizeof(freq));
        int multiple = 0;
        for(int i=0; i<n; i++){
            int& a = freq[s[i]-'a'];
            a++;
            if(a>1){
                cout<<s[i]<<endl;
                multiple = true;
            }
            if( s[i] != goal[i] ){
                if(!count) idx1 = i;
                if(count==1) idx2 = i;
                count++;
            }
            if( count > 2 ){
                return false;
            }
        }

        if( s == goal ){
            return multiple;
        }

        if( s[idx2] == goal[idx1] && s[idx1] == goal[idx2] ) return true;

        return false;
        
    }
};