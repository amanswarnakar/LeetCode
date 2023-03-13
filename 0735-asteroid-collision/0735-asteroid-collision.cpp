class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
      stack<int> st;
      for(int i = 0; i < v.size(); i++){
        if(v[i] > 0 or st.empty()) st.push(v[i]);
        else {
          while(!st.empty() and st.top() > 0 and st.top() < abs(v[i]))
            st.pop();
          if(!st.empty() and st.top() == abs(v[i])) st.pop();
          else if(st.empty() or st.top() < 0)
            st.push(v[i]);
        }        
      }

      vector<int> ans(st.size());
      for(int i = st.size() - 1; i >= 0; i--){
        ans[i] = st.top();
        st.pop(); 
      }
      return ans;
    }
};