class MyStack {
public:
    vector<int>vec;
    MyStack() {
        vec.clear();
    }
    
    void push(int x) {
        vec.push_back(x);
    }
    
    int pop() {
        int lst = vec.back();
        vec.pop_back();
        return lst;
    }
    
    int top() {
        int lst = vec.back();
        return lst;
    }
    
    bool empty() {
        return !vec.size();
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