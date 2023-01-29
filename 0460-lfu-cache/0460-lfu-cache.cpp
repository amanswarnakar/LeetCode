struct Node {
  int key, value, cnt;
  Node *next, *prev;
  Node(int _key, int _value){
    key = _key;
    value = _value;
    cnt = 1;
  }
};

struct List {
  int size;
  Node *head, *tail;
  List(){
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
    size = 0;
  }
  void addNode(Node *node){
    Node *temp = head->next;
    node->next = temp;
    node->prev = head;
    head->next = node;
    temp->prev = node;
    size++;
  }
  void removeNode(Node *delNode){
    Node *delPrev = delNode->prev, *delNext = delNode->next;
    delPrev->next = delNext;
    delNext->prev = delPrev;
    size--;
  }
};

class LFUCache {
public:
  map<int, Node*> keyNode;
  map<int, List*> freqMap;
  int size, minFreq, currSize; 
  LFUCache(int capacity) {
    size = capacity;
    minFreq = 0;
    currSize = 0;
  }
  
  void updateFreqMap(Node *node){
    keyNode.erase(node->key);
    freqMap[node->cnt]->removeNode(node);
    if(node->cnt == minFreq and freqMap[node->cnt]->size == 0) 
      minFreq++;
    List *nextFreqMap = new List();
    if(freqMap.find(node->cnt + 1) != freqMap.end())
      nextFreqMap = freqMap[node->cnt + 1];
    node->cnt++;
    nextFreqMap->addNode(node);
    freqMap[node->cnt] = nextFreqMap;
    keyNode[node->key] = node;
  }
  
  int get(int key) {
    if(keyNode.find(key) != keyNode.end()){
      Node *node = keyNode[key];
      int value = node->value;
      updateFreqMap(node);
      return value;
    }
    return -1;
  }

  void put(int key, int value) {
    if(size == 0) return;
    if(keyNode.find(key) != keyNode.end()){
      Node *node = keyNode[key];
      node->value = value;
      updateFreqMap(node);
    } else {
      if(currSize == size){
        List *list = freqMap[minFreq];
        keyNode.erase(list->tail->prev->key);
        freqMap[minFreq]->removeNode(list->tail->prev);
        currSize--;
      }
      currSize++;
      minFreq = 1;
      List *list = new List();
      if(freqMap.find(minFreq) != freqMap.end()){
        list = freqMap[minFreq];
      }
      Node *node = new Node(key, value);
      list->addNode(node);
      keyNode[key] = node;
      freqMap[minFreq] = list;
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */