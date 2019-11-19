/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(!pListHead) return nullptr;
        
        ListNode* cur = pListHead;
        while(cur && k--)
            cur = cur->next;
        if(!cur && k != 0) return nullptr; //没有k个节点
        ListNode* ans = pListHead;
        while(cur) {
            ans = ans->next;
            cur = cur->next;
        }
        return ans;
    }
};