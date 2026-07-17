class MinStack {
    stack<int> s1;
    stack<int> minStack ;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        s1.push(value);

        if(minStack.empty()){
            minStack.push(value);
        }
        else{
            minStack.push(min(minStack.top(),value));
        }
    }
    
    void pop() {
        s1.pop();
        minStack.pop();
    }
    
    int top() {
        if(!s1.empty()){
            return s1.top();
        }
        else{
            return -1 ;
        }
    }
    
    int getMin() {
        if(!minStack.empty()){
            return minStack.top();
        }
        else{
            return -1 ;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */