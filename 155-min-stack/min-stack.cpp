#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<int> minimumz;
    stack<int> st;
    MinStack() {
        minimumz.push(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        if(minimumz.top()>val){
            minimumz.push(val);
        }else{
            minimumz.push(minimumz.top());
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        int ele = st.top();
        st.pop();
        minimumz.pop();
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        return st.top();
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }
        return minimumz.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */