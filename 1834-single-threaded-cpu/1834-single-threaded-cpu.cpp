class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& v) {
      vector<int> ans;
      int n = v.size(), i = 0;
      for(int i = 0; i < n; i++)
        v[i].emplace_back(i);
      sort(v.begin(), v.end());
      long long int time = v[0][0];
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      while(i < n or !pq.empty()){
        while(i < n and time >= v[i][0]){
          pq.push({v[i][1], v[i][2]});
          i++;
        }
        if(pq.empty()) time = v[i][0];
        else {
          auto [x, y] = pq.top(); pq.pop();
          ans.emplace_back(y);
          time += x;
        }
      }
      return ans;
    }
};