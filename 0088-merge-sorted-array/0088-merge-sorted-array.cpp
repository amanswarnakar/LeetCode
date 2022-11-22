class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
      int i = m-1, j = n-1, k = m+n-1;
      while(i >= 0 and j >= 0){
        if(a[i] > b[j])
          a[k--] = a[i--];
        else 
          a[k--] = b[j--];
      }
      while(j >= 0){
        a[k--] = b[j--];
      }
      
      // for(int i = m; i < m+n; i++){
      //   a[i] = b[i-m];
      // }
      // sort(a.begin(), a.end());
    }
};