class Solution {
public:
    static bool comparator(vector<int> &a, vector<int> &b){ 
      // Sorting in descending order for first element and ascending for second element
      if(a[0] != b[0])
        return a[0] > b[0];
      return a[1] < b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
      sort(prop.begin(), prop.end(), comparator);
      // for(auto i : prop){
      //   for(auto j : i){
      //     cout<<j<<" ";
      //   } cout<<"\n";
      // }
      int maxDef = INT_MIN;
      int ans=0;
      for(int i = 0; i < prop.size(); i++){
          if(maxDef > prop[i][1]) ans++;
          else maxDef = prop[i][1];
      }
      return ans;
    }
};