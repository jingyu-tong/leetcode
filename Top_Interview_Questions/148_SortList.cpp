/*
**merge sort top-down T(n) = O(nlogn) S(n) = O(logn)
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *fast = head, *slow = head;
        
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(mid));
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while(l1 && l2) {
            if(l1->val > l2->val) {
                cur->next = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
/*
**merge sort bottom-up T(n) = O(nlogn) S(n) = O(1)
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //使用bottom-up方式求解
        if(!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = head;
        int len = 1;//the length of the list
        while(cur = cur->next){ 
            ++len;
        }
        ListNode* left=head, *right = head;//两部分的链首
        for(int i = 1; i < len; i <<= 1){
            cur = dummy.next;
            ListNode* tail = &dummy;//left前的元素
            left = cur;
            while(left){
                left = cur;
                right = spilt(left, i);
                cur = spilt(right, i);
                auto merged = merge(left, right);
                tail->next = merged.first;
                tail = merged.second;
            }
        } 
        return dummy.next;
    }
private:
    ListNode* spilt(ListNode* start, int n){
        ListNode* rest = start;
        while(--n && start){
            start = start->next;
        }
        rest = start ? start->next : nullptr;
        if(start) start->next = nullptr;
        return rest;
    }
    pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        while(tail->next) tail = tail->next;
        return {dummy.next, tail};
    }
};