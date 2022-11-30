class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      unordered_set<int> st;
      unordered_map<int, int> um;
      for(auto &i : arr){
        um[i]++;
      }
      for(auto &p: um){
        if(!st.count(p.second))
          st.insert(p.second);
        else return false;
      }
      return true;  
    }
};