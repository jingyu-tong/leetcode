class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head, nullptr);
    }
    TreeNode* buildBST(ListNode* head, ListNode* tail) {
        if(head == tail) return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }

        TreeNode* node = new TreeNode(slow->val);
        node->left = buildBST(head, slow);
        node->right = buildBST(slow->next, tail);
        return node;
    }
};
