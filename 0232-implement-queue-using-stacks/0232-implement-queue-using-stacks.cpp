class MyQueue {
public:
    stack<int> st, temp;
    MyQueue() {
        
    }
    
    void push(int x) {
      st.emplace(x);
      while(!st.empty()){
        auto top = st.top(); st.pop();
        temp.emplace(top);
      }
      while(!temp.empty()){
        auto top = temp.top(); temp.pop();
        st.emplace(top);
      }
    }
    
    int pop() {
      while(!st.empty()){
        auto top = st.top(); st.pop();
        temp.emplace(top);
      }
      int res = temp.top();
      temp.pop();
      while(!temp.empty()){
        auto top = temp.top(); temp.pop();
        st.emplace(top);
      }
      return res;
    }
    
    int peek() {
      while(!st.empty()){
        auto top = st.top(); st.pop();
        temp.emplace(top);
      }
      int res = temp.top();
      while(!temp.empty()){
        auto top = temp.top(); temp.pop();
        st.emplace(top);
      }
      return res;
    }
    
    bool empty() {
      return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */