#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isItPossible(string& word1, string& word2) {
        int f1[26] = {0};
        int f2[26] = {0};

        int n1 = word1.length(), n2 = word2.length();

        int dis_count1 = 0, dis_count2 = 0;

        for(int i=0; i<n1; i++){
            int idx = word1[i] - 'a';
            if(!f1[idx]) dis_count1++;
            f1[idx]++;
        }

        for(int j=0; j<n2; j++){
            int idx = word2[j]-'a';
            if(!f2[idx]) dis_count2++;
            f2[idx]++;
        }

        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                if( f1[i] && f2[j] ){
                    /* Now, swap them and see if we can make the distinct values equal */
                    f1[i]--;
                    f1[j]++;
                    
                    f2[j]--;
                    f2[i]++;

                    int t1 = 0, t2 = 0;
                    for(int i=0; i<26; i++){
                        t1 += f1[i] ? 1 : 0;
                    }
                    for(int i=0; i<26; i++){
                        t2 += f2[i] ? 1 : 0;
                    }

                    f1[i]++;
                    f1[j]--;

                    f2[j]++;
                    f2[i]--;
                    //cout<<i<<" "<<j<<endl;
                    if( t1 == t2 ) return true;
                }
            }
        }

        return false;
    }
};