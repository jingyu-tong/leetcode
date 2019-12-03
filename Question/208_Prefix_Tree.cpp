class Trie {
public:
    /** Initialize your data structure here. */
    Trie():root_(new TreeNode()) {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode* node = root_;
        for(const auto& ch : word) {
            if(!node->children_[ch - 'a']) {
                node->children_[ch - 'a'] = new TreeNode();
            }
            node = node->children_[ch - 'a'];
        }
        node->valid_ = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode* node = root_;
        for(const auto& ch : word) {
            if(!node->children_[ch - 'a']) {
                return false;
            }
            node = node->children_[ch - 'a'];
        }
        return node->valid_;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode* node = root_;
        for(const auto& ch : prefix) {
            if(!node->children_[ch - 'a']) {
                return false;
            }
            node = node->children_[ch - 'a'];
        }
        return true;
    }
private:
    struct TreeNode {
        TreeNode() : valid_(false), children_(26, nullptr) {
            
        }
        
        vector<TreeNode*> children_;
        bool valid_;
    };
    
    TreeNode* root_;
};
