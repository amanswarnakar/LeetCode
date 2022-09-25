class MyCircularQueue {
public:
    vector<int> q;
    int s{}, cnt{}, head{}; // s = size, cnt = number of elements in q, head = index of head element
    MyCircularQueue(int k) {
      q.resize(k);
      s = k; head = 0; cnt = 0;
    }
    
    bool enQueue(int value) {
      if(isFull()) return false;
      q[(head + cnt) % s] = value;
      cnt++; 
      return true;
    }
    
    bool deQueue() {
      if(isEmpty()) return false;
      cnt--; head = (head + 1) % s;
      return true;
    }
    
    int Front() {
      if(isEmpty()) return -1;
      return q[head];
    }
    
    int Rear() {
      if(isEmpty()) return -1;
      return q[(head + cnt - 1) % s];
    }
    
    bool isEmpty() {
      if(cnt == 0) return true;
      return false;
    }
    
    bool isFull() {
      if(cnt == s) return true;
      return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */