class TrieNode {
public:
  bool isLeaf;
  TrieNode *children[26];
  TrieNode() {
    this->isLeaf = false;
    for(int i = 0; i < 26; i++){
      this->children[i] = NULL;
    }
  }
};

class Trie {
  TrieNode *root;
public:
  
    Trie() {
      root = new TrieNode();
    }
    
    void insert(string word) {
      TrieNode *node = root;
      for(auto &c: word){
        int idx = c - 'a';
        if(node->children[idx] == NULL) node->children[idx] = new TrieNode();
        node = node->children[idx];
      }
      node->isLeaf = true;
    }
    
    bool search(string word) {
      TrieNode *node = root;
      for(auto &c: word){
        int idx = c - 'a';
        if(node->children[idx] == NULL) return false;
        node = node->children[idx];
      }
      return node->isLeaf == true;
    }
    
    bool startsWith(string prefix) {
      TrieNode *node = root;
      for(auto &c: prefix){
        int idx = c - 'a';
        if(node->children[idx] == NULL) return false;
        node = node->children[idx];
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */