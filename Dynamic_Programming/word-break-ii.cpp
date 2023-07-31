class Solution {
public:
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(string& str : wordDict){
            dict.insert(str);
        }

        vector<string> ans;
        solve(s,0,dict,"",ans);
        return ans;
     
    }

    void solve(string& s, int k, unordered_set<string>& dict, string r,
    vector<string>& ans){
        int len = s.length();
        if( k >= len ){
            r.pop_back();
            ans.push_back(r);
            return ;
        }

        string str = "";
        for(int i=k; i<len; i++){
            str += s[i];
            if( dict.find(str) != dict.end() ){
                solve(s,i+1,dict,r + str + " ", ans);
            }
        }
    }
};
