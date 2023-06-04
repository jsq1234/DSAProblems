#include <numeric>
#define all(v) (v).begin(),(v).end()
#include <algorithm>
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

template<typename T>
void log(vector<T>& vec, const string s = ""){
    if(!s.empty()){
        cout<<s<<" : ";
    }
    auto print = [](T& x){ cout<<x<<" "; };
    for_each(all(vec),print);
    cout<<endl;
}

template <typename T>
void log(vector<vector<T>>& vec, const string& s = ""){
    if(!s.empty()){
        cout<<s<<" : ";
    }
    auto print = [](const vector<T>& v){
        for(const T& x : v){
            cout<<x<<" ";
        }
        cout<<endl;
    };
    for_each(all(vec),print);
}
template<typename T>
long long sum(const vector<T>& vec){
    return accumulate(all(vec),0); 
}
