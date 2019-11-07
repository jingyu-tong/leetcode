class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }

    int get(int key) {
        auto iter = mem_.find(key);
        if(iter == mem_.end()) return -1;
        cache_.splice(cache_.begin(), cache_, iter->second);
        return iter->second->second;
    }

    void put(int key, int value) {
        auto iter = mem_.find(key);
        //already in cache, update cache_ and mem_
        if(iter != mem_.end()) {
            cache_.splice(cache_.begin(), cache_, iter->second);
            iter->second->second = value;
            return;
        }

        //new key, might del key
        if(cache_.size() == capacity_) {
            auto& temp = cache_.back();
            mem_.erase(temp.first);
            cache_.pop_back();
        }
        cache_.emplace_front(key, value);
        mem_[key] = cache_.begin();
    }
private:
    int capacity_;
    list<pair<int, int>> cache_; //key, val
    unordered_map<int, list<pair<int, int>>::iterator> mem_; //key, iter
};
