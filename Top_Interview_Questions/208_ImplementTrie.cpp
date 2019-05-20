class Trie {
public:
    /** Initialize your data structure here. */
    Trie():root_(new TrieNode()) {
        
    }
    ~Trie() {
        if(root_) delete root_;
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root_;
        for(auto ch : word) {
            if(!p->children_[ch - 'a']) {
                p->children_[ch - 'a'] = new TrieNode();
            }
            p = p->children_[ch - 'a'];
        }
        p->is_word_ = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        const TrieNode* p = find(word);
        return p && p->is_word_;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
private:
    struct TrieNode {
        TrieNode():is_word_(false), children_(26, nullptr){
            
        }
        ~TrieNode() {
            for(auto child : children_)
                if(child) delete child;
        }
        bool is_word_;
        vector<TrieNode*> children_;
    };
    TrieNode* root_;
    const TrieNode* find(const string& prefix) const {
        const TrieNode* p = root_;
        for(auto ch : prefix) {
            p = p->children_[ch - 'a'];
            if(p == nullptr) break;
        }
        return p;
    }
};
