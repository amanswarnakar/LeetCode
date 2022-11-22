class Solution {
public:
    int numSquares(int n) {
      queue<int> q;
      unordered_set<int> st;
      for(int i = 1; i * i <= n; i++){
        st.insert(i * i); 
        q.emplace(i * i);
      }
      int ans = 1;
      while(!q.empty()){
        int sz = q.size();
        while(sz--){
          auto top = q.front();
          q.pop();
          if(top == n) return ans;
          for(int i = 1; i * i <= n; i++){
            int temp = top + i * i;
            if(temp <= n and !st.count(temp)){
            cout<<temp<<" ";
              q.emplace(temp);
              st.insert(temp);
            }
          }
          cout<<endl;
        }
        ans++;
      }
      return ans;
    }
};