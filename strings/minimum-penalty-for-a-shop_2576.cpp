/*

"YYNY";

"NNNNN";

"YYYY";

*/
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int no[100009] = {0};
        int yes[100009] = {0};

        for(int i=1; i<=n; i++){
            if(customers[i-1] == 'N') no[i] = no[i-1] + 1;
            else no[i] = no[i-1];
        }
        for(int j=n-1; j>=0; j--){
            if(customers[j] == 'Y') yes[j] = yes[j+1] + 1;
            else yes[j] = yes[j+1];
        }

        int idx = n;
        int penalty = INT_MAX;
        for(int i=0; i<=n; i++){
            int cur_penalty = no[i] + yes[i];
            if(cur_penalty < penalty){
                idx = i;
                penalty = cur_penalty;
            }
        }
        return idx;
    }
};