class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, nullptr);
    }
private:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
        if(head == tail) return nullptr;
        
        ListNode* fast = head, * slow = head;
        while(fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        TreeNode* node = new TreeNode(slow->val);
        node->left = sortedListToBST(head, slow);
        node->right = sortedListToBST(slow->next, tail);
        return node;
    }
};
