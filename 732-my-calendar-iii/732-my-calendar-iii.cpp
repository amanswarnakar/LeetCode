class MyCalendarThree {
public:
    vector<int> s, e;
    MyCalendarThree() {
      s.resize(0);
      e.resize(0);
    }
    
    int book(int start, int end) {
      s.push_back(start);
      e.push_back(end);
      sort(s.begin(), s.end());
      sort(e.begin(), e.end());
      int n = s.size();
      int i = 1, j = 0, cnt = 1, ans = 1;
      while(i < n and j < n){
        // cout<<s[i]<<" "<<e[i]<<"~"<<ans<<endl;
        if(s[i] < e[j]){
          cnt++; i++;
        } else{
          cnt--; j++;
        }
        ans = max(ans, cnt);
      }
      return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */