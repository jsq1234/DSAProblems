/*

"hit"
"cog"
["hot","dot","dog","lot","log","cog"];

"hit"
"cog"
["hot","dot","dog","lot","log"];

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string& beginWord, string& endWord, vector<string>& wordList)
    {
        unordered_set<string> st;
        int n = beginWord.size();
        vector<unordered_set<char>> fq(n);
        for(int i=0; i<wordList.size(); i++){
            string& s = wordList[i];
            st.insert(s);
            for(int j=0; j<n; j++){
                fq[j].insert(s[j]);
            }
        }

        queue<string> Q;
        Q.push(beginWord);

        int level = 0;

        while(!Q.empty()){
           int size = Q.size();
           for(int l=0; l<size; l++){
               string s = Q.front();
               if( s == endWord ) return level; 
               Q.pop();
               for(int j=0; j<n; j++){
                   unordered_set<char> ch = fq[j];
                   char orig = s[j];
                   for(char x : ch){
                       if(x != orig){
                           s[j] = x;
                           Q.push(s);
                       }
                   }
               }
           }
           level++;
        }


        return 0;
    }
};
