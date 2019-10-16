class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return {};
        int n = lists.size();
        while(n > 1) {
            int mid = (n + 1) / 2;
            for(int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + mid]);
            }
            n = mid;
        }
        return lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* head = &dummy;
        while(l1 && l2) {
            if(l1->val > l2->val) {
                head->next = l2;
                head = head->next;
                l2 = l2->next;
            } else {
                head->next = l1;
                head = head->next;
                l1 = l1->next;
            }
        }
        head->next = l1 != nullptr ? l1 : l2;
        return dummy.next;
    }
};
