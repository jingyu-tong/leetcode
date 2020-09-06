//页面置换算法简易实现
//LRU
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }

    int get(int key) {
        auto iter = mem_.find(key);
        if(iter == mem_.end()) return -1;

        cache_.splice(cache_.begin(), cache_, iter->second); //iter 插入头

        return iter->second->second;
    }

    void put(int key, int value) {
        auto iter = mem_.find(key);
        if(iter != mem_.end()) { //already in cache
            iter->second->second = value;
            cache_.splice(cache_.begin(), cache_, iter->second); //iter 插入头
            return;
        }

        if(cache_.size() == capacity_) {
            const auto &temp = cache_.back();
            mem_.erase(temp.first);
            cache_.pop_back();
        }
        cache_.emplace_front(key, value);
        mem_[key] = cache_.begin();
    }
    int capacity_;
    list<pair<int, int>> cache_; //key, val
    unordered_map<int, list<pair<int, int>>::iterator> mem_; //key, iter
};

//LFU
struct CacheNode {
    int key;
    int val;
    int freq;
    list<int>::iterator it;
};

class LFUCache {
public:
    LFUCache(int capacity): capacity_(capacity), min_freq_(0){

    }

    int get(int key) {
        auto iter = mem_.find(key);
        if(iter == mem_.end()) return -1;

        touch(iter->second);
        return iter->second.val;
    }

    void put(int key, int value) {
        if(capacity_ == 0) return;

        auto iter = mem_.find(key);
        if(iter != mem_.end()) {
            iter->second.val = value;
            touch(iter->second);
            return;
        }

        //删除
        if(mem_.size() == capacity_) {
            int key_delete = l_[min_freq_].back();
            l_[min_freq_].pop_back();

            mem_.erase(key_delete);
        }

        min_freq_ = 1;
        l_[min_freq_].push_front(key);
        mem_[key] = {key, value, 1, l_[1].begin()};

    }


    //更新list
    void touch(CacheNode& node) {
        int prev_freq = node.freq;
        int freq = ++(node.freq);

        l_[prev_freq].erase(node.it);
        if(l_[prev_freq].empty() && prev_freq == min_freq_) {
            l_.erase(prev_freq);
            ++min_freq_;
        }

        l_[freq].push_front(node.key);

        node.it = l_[freq].begin();
    }

    int capacity_;
    int min_freq_;
    unordered_map<int, CacheNode> mem_; //key, node
    unordered_map<int, list<int>> l_; // freq, key_list
};
