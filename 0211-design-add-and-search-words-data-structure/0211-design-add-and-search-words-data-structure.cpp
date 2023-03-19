class TrieNode {
  public:
    bool isLeaf;
    TrieNode *children[26];
    TrieNode() {
      this->isLeaf = false;
      for(int i = 0; i < 26; i++)
        this->children[i] = NULL;
    }
};
class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
      root = new TrieNode();
    }
    
    void addWord(string word) {
      TrieNode *node = root;
      for(auto &ch: word){
        int idx = ch - 'a';
        if(node->children[idx] == NULL) node->children[idx] = new TrieNode();
        node = node->children[idx];
      }
      node->isLeaf = true;
    }
    
    bool search(string word) {
      return helper(word, root);
    }
  
    bool helper(string word, TrieNode *node){
      int n = word.size();
      for(int i = 0; i < n; i++){
        char ch = word[i];
        if(ch == '.'){
          for(auto c: node->children)
            if(c and helper(word.substr(i + 1), c)) return true;
          return false;
        }
        int idx = ch - 'a';
        if(node->children[idx] == NULL) return false;
        node = node->children[idx];
      } 
      return node->isLeaf;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */