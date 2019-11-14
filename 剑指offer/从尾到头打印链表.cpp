class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if(!head) return {};
        vector<int> ans;
        ListNode* cur = head;
        while(head) {
            ans.push_back(head->val);
            head = head->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};