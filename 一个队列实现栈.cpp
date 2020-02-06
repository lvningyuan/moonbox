class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
            q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int oldsize = q.size();
        while(oldsize >1)
        {
            q.push( q.front() );
            q.pop();
            oldsize--;
        }
        int dst = q.front();
        q.pop();
        return dst;
    }
    
    /** Get the top element. */
    int top() {
            return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
            return q.empty();
    }
    private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */