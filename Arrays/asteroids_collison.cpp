class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i=0; i<n; i++){
            if( st.empty() || 
                st.top() > 0 && asteroids[i] > 0 ||
                st.top() < 0 && asteroids[i] < 0 ||
                st.top() < 0 && asteroids[i] > 0 
                ){
                    st.push(asteroids[i]);
                    continue;
                }
            int destroyed = false;
            while(!st.empty() && st.top() > 0 ){
                if(abs(st.top()) >= abs(asteroids[i])){
                    destroyed = true;
                    if(abs(st.top()) == abs(asteroids[i])){
                        st.pop();
                    }
                    break;
                }
                if(abs(st.top()) < abs(asteroids[i])){
                    st.pop();
                }
            }
            if(!destroyed){
                st.push(asteroids[i]);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
