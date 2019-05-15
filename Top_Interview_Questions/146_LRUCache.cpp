class LRUCache {
public:
    LRUCache(int capacity):capacity_(capacity) {
        
    }
    
    int get(int key) {
        const auto temp = mem_.find(key);
        if(temp == mem_.end()) return -1;
        //移动到前端，表示最近被使用
        cache_.splice(cache_.begin(), cache_, temp->second);
        return temp->second->second;
    }
    
    void put(int key, int value) {
        const auto temp = mem_.find(key);
        
        if(temp != mem_.end()) {
            temp->second->second = value;
            cache_.splice(cache_.begin(), cache_, temp->second);
            return;
        }
        
        if(cache_.size() == capacity_) {
            const auto &node = cache_.back();
            mem_.erase(node.first);
            cache_.pop_back();
        }
        
        cache_.emplace_front(key, value);
        mem_[key] = cache_.begin();
    }
private:
    int capacity_;
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> mem_;
};