### 208\. [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)

Implement a trie with insert, search, and startsWith methods.

Example:
```
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
```

Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

#### Solution 1

C++

```
struct TrieNode {
    TrieNode *child[26];
    bool isWord;
    TrieNode(): isWord(false) {
        for (auto &a : child) a = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        TrieNode *cur = root;
        for (char & c : s) {
            int i = c - 'a';
            if (!cur->child[i]) cur->child[i] = new TrieNode();
            cur = cur->child[i];
        }
        cur->isWord = true;
    }
    bool search(string key) {
        TrieNode *cur = root;
        for (char & c : key) {
            int i = c - 'a';
            if (!cur->child[i]) return false;
            cur = cur->child[i];
        }
        return cur->isWord;
    }
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (char & c : prefix) {
            int i = c - 'a';
            if (!cur->child[i]) return false;
            cur = cur->child[i];
        }
        return true;
    }
    
private:
    TrieNode* root;
};
```
