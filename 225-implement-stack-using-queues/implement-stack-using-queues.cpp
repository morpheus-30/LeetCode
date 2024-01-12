class MyStack {
public:
    queue<int> q;

    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.empty()){
            return -1;
        }
        queue<int> temp;
        while(q.size()!=1){
            temp.push(q.front());
            q.pop();
        }
        int myele = q.front();
        q.pop();
        q = temp;
        return myele;
    }
    
    int top() {
        if(q.empty()){
            return -1;
        }
        queue<int> temp;
        int myele = q.front();
        while(!q.empty()){
            myele = q.front();
            temp.push(myele);
            q.pop();
        }
        q = temp;
        return myele;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */