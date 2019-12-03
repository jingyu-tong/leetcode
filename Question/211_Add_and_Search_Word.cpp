class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary(): root_(new TreeNode()) {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TreeNode* node = root_;
        for(const auto& ch : word) {
            if(!node->children_[ch - 'a']) {
                node->children_[ch - 'a'] = new TreeNode();
            }
            node = node->children_[ch - 'a'];
        }
        node->valid_ = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word, 0, root_);
    }
private:
    struct TreeNode {
        TreeNode() : valid_(false), children_(26, nullptr) {
            
        }
        
        vector<TreeNode*> children_;
        bool valid_;
    };
    //node的孩子对应cur
    bool dfs(string& word, int cur, TreeNode* node) {
        if(!node) return false;
        if(cur == word.size()) {
            return node->valid_;
        }
        
        if(word[cur] == '.') {
            for(int i = 0; i < 26; ++i) {
                if(dfs(word, cur + 1, node->children_[i])) return true;
            }
            return false;
        } 
        
        return dfs(word, cur + 1, node->children_[word[cur] - 'a']);
    }
    TreeNode* root_;
};
