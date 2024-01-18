#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<int> getSmallerIndexLeft(vector<int> v){
        stack<int> st;
        int n = v.size();
        vector<int> toBeReturned(n+1);
        for(int i = 0;i<n;i++){
            while(!st.empty()&&v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.empty()){
                toBeReturned[i] = -1;
            }else{
                toBeReturned[i] = st.top();
            }
            st.push(i);
        }
        return toBeReturned;
    }
    vector<int> getSmallerIndexRight(vector<int> v){
        stack<int> st;
        int n = v.size();
        vector<int> toBeReturned(n+1);
        for(int i = n-1;i>=0;i--){
            while(!st.empty()&&v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.empty()){
                toBeReturned[i] = n;
            }else{
                toBeReturned[i] = st.top();
            }
            st.push(i);
        }
        return toBeReturned;
    }

    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==1){
            return heights[0];
        }
        vector<int> left = getSmallerIndexLeft(heights);
        vector<int> right = getSmallerIndexRight(heights);
        int maxi = 0;
        int n = heights.size();
        for(int i=0;i<n;i++){
            int maxArea = (right[i]-left[i]-1)*heights[i];
            maxi = max(maxi,maxArea);
        }
        return maxi;
        
    }
};