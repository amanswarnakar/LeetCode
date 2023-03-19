class Solution {
public:
    int findSmallestInteger(vector<int>& v, int val) {
      unordered_map<int, int> um;
      for(int i = 0; i < v.size(); i++){
        // um[((v[i] % val) + val) % val]++;
        v[i] %= val;
        if(v[i] < 0) v[i] += val;
        um[v[i]]++;
      }
      for(int i = 0; i <= v.size(); i++){
        int rem = i % val;
        if(um.count(rem) and um[rem] > 0) um[rem]--;
        else return i;
      }
      return 0;
    }
};