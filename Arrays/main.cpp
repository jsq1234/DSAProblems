#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> st;
    st.insert(4);
    st.insert(3);
    st.insert(22);
    st.insert(14);
    st.insert(10);
    st.insert(19);
    st.insert(17);

    set<int>::reverse_iterator endItr = st.rbegin();
    set<int>::iterator startItr = st.begin();
    cout<<*endItr<<" "<<*startItr<<endl;

}