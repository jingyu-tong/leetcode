class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return nullptr;
        
        unordered_map<RandomListNode*, RandomListNode*> mem; //old node new node
        auto* cur = pHead;
        mem[cur] = new RandomListNode(cur->label);
        auto* prev = cur;
        cur = cur->next;
        
        while(cur) {
            if(mem.count(cur) == 0) { //new node
                mem[cur] = new RandomListNode(cur->label);
            }
            mem[prev]->next = mem[cur];
            prev = cur;
            cur = cur->next;
        }
        
        //random pointer
        cur = pHead;
        while(cur) {
            mem[cur]->random = mem[cur->random];
            cur = cur->next;
        }
        return mem[pHead];
    }
};