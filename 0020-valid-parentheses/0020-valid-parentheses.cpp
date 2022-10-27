class Solution {
public:
    bool isValid(string s) {
      stack<char> stk;
      for(char ch: s){
        if(ch == '(' or ch == '{' or ch == '[') stk.push(ch);
        else {
          if(stk.empty() or (stk.top() == '(' and ch != ')') or (stk.top() == '{' and ch != '}') or (stk.top() == '[' and ch != ']')) return false;
          stk.pop();
        }
      }
      return stk.empty();
    }
};