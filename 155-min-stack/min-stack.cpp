class MinStack {
public:
    stack<int>st;
    vector<int>v;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        v.push_back(val);
        sort(v.begin(), v.end());
    }
    
    void pop() {
        int num = st.top();
        st.pop();
        int index = -1;
        for(int i=0; i<v.size(); i++) {
            if(v[i] == num) {
                index = i;
                break;
            }
        }
        v.erase(v.begin() + index);
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return v[0];
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